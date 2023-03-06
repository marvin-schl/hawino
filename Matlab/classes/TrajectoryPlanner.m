classdef TrajectoryPlanner
    %UNTITLED6 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        path
        qAccMax
        qVelMax
        
        lastPos
        searchPos
        searchStepWidth
        searchTol
        currentStep
        nextSwitchingPoint
        
        posBackward
        velBackward
        
        pos  
        vel  
        acc   
        dt   
        k
        j
    end
    
    methods
        function obj = TrajectoryPlanner(path, qAccMax, qVelMax)
            obj.path = path;
            obj.qAccMax = struct("x", qAccMax(1), "y", qAccMax(2));
            obj.qVelMax = struct("x", qVelMax(1), "y", qVelMax(2));
            
            obj.searchTol       = 0.2;
            obj.searchStepWidth = 1e-3;
            obj.searchPos       = 0;
            obj.lastPos         = 0;
            
            obj.posBackward    = zeros(1000,1);
            obj.pos            = zeros(1000,1);
            obj.vel            = zeros(1000,1);
            obj.acc            = zeros(1000,1);
            obj.dt             = [];
        end
                
        
        function obj = generateTrajectory(obj, dt)
        obj.k = 1;
        obj.currentStep = 1;
        obj.dt = dt;
           while obj.pos(obj.k) < obj.path.length
            obj.currentStep
            switch obj.currentStep             
                case 1
                    obj = obj.step1();
                case 2
                    obj = obj.step2();
                case 3
                    obj = obj.step3();
                case 4
                    obj = obj.step4();
                case 5
                    try
                        obj = obj.step5();
                    catch
                    end
                otherwise
                    throw(MException("TrajectoryPlanner:InvalidState","Entered an invalid state"));
            end
            
            if (obj.k > 1000)
                disp(sprintf("Run out of array elemets"))
                break
            end
           end
        end
        
        %velocity limit and its derivative, eq. (36), (37), (31)
        function [velMax, dvelMax, velMaxAcc] = velMax(obj, s) 
            [dx, dy]     = obj.path.diff(s);
            %[ddx,ddy]    = obj.path.diff(s,2);
            [ddx, ddy]     = obj.path.getMaxSegmentCurvature(s);

            velMax       = zeros(length(dx),1);
            dvelMax      = zeros(length(dx),1);
            velMaxAcc    = zeros(length(dx),1);


             for i=1:length(dx)
               if dx(i) < 1e-6
                    velMax(i) = obj.qVelMax.y/abs(dy(i)); 
                    dvelMax(i) = -obj.qVelMax.y*ddy(i)/(dy(i)*abs(dy(i))); 
                    
                    if ddx(i) ~= 0
                        %velMaxAcc(i) = sqrt(obj.qAccMax.x/abs(ddx(i)));
                        velMaxAcc(i) = sqrt(obj.qAccMax.x/abs(ddx(i)));
                    else   
                        velMaxAcc(i) = velMax(i);
                    end
               elseif dy(i) < 1e-6
                   
                   velMax(i)  =  obj.qVelMax.x/abs(dx(i));
                   dvelMax(i) =  -obj.qVelMax.x*ddy(i)/(dx(i)*abs(dx(i)));
                   
                    if ddy ~= 0
                        %velMaxAcc(i) = sqrt(obj.qAccMax.y/abs(ddy(i)));
                        velMaxAcc(i) = sqrt(obj.qAccMax.y/abs(ddy(i)));

                    else                        
                        velMaxAcc(i) =  velMax(i);
                    end
               else
                   velMaxX = obj.qVelMax.x/abs(dx(i));
                   velMaxY = obj.qVelMax.y/abs(dy(i));
                   velMax(i) = min(velMaxX, velMaxY);
                   
                   if  velMaxY >  velMaxX
                     dvelMax(i) = -obj.qVelMax.x*ddx(i)/(dx(i)*abs(dx(i)));
                   else
                     dvelMax(i) = -obj.qVelMax.y*ddy(i)/(dy(i)*abs(dy(i)));
                   end
                   
                   ddxdx = ddx(i)/dx(i);
                   ddydy = ddy(i)/dy(i);
                   velAccLimCandidate1 = velMax(i);
                  if (abs(ddxdx-ddydy) > 1e-6) 
                       velAccLimCandidate1 = sqrt((obj.qAccMax.x/abs(dx(i))+ obj.qAccMax.y/(abs(dy(i))))/abs(ddxdx-ddydy));
                  
                  end
                  
                   if ddx(i) < 1e-6 && ddy(i) > 1e-6
                       velAccLimCandidate2 = sqrt(obj.qAccMax.y/abs(ddy(i)));
                   elseif ddx(i) > 1e-6 && ddy(i) < 1e-6
                       velAccLimCandidate2 = sqrt(obj.qAccMax.x/abs(ddx(i)));
                   elseif ddx(i) > 1e-6 && ddx(i) > 1e-6
                       velAccLimCandidate2 = min(sqrt(obj.qAccMax.y/abs(ddy(i))), sqrt(obj.qAccMax.x/abs(ddx(i))));
                   else
                       velAccLimCandidate2 = velMax(i);
                   end
                   velMaxAcc(i) = min(velAccLimCandidate1, velAccLimCandidate2);
               end
              end
        end
        
        %upper and lower acceleration limit eq. (22), (23)
        function [accMin, accMax] = accLim(obj, s, vel)
            [dx, dy]     = obj.path.diff(s);
           %[ddx,ddy]    = obj.path.diff(s,2);
           [ddx, ddy]     = obj.path.getMaxSegmentCurvature(s);

            accMin          = zeros(length(dx),1);
            accMax          = zeros(length(dx),1);
           
            for i=1:length(dx)
               if dx(i) < 1e-6
                    accMin(i) = (-obj.qAccMax.y/abs(dy(i)) - ddy(i)*vel(i)^2/dy(i));               
                    accMax(i) = (obj.qAccMax.y/abs(dy(i))  - ddy(i)*vel(i)^2/dy(i));   

               elseif dy(i) < 1e-6
                   accMin(i) = (-obj.qAccMax.x/abs(dx(i))-ddx(i)*vel(i)^2/dx(i));
                   accMax(i) = (obj.qAccMax.x/abs(dx(i))-ddx(i)*vel(i)^2/dx(i));
               else
                    accMinX = (-obj.qAccMax.x/abs(dx(i)) - ddx(i)*vel(i)^2/dx(i));
                    accMaxX = (obj.qAccMax.x/abs(dx(i)) -ddx(i)*vel(i)^2/dx(i));
                    accMinY = (-obj.qAccMax.y/abs(dy(i))-ddy(i)*vel(i)^2/dy(i));               
                    accMaxY = (obj.qAccMax.y/abs(dy(i))-ddy(i)*vel(i)^2/dy(i));
                   
                    accMin(i) = max(accMinX, accMinY);
                    accMax(i) = min(accMaxX, accMaxY);
               end
            end
        end
  
        function obj = step1(obj)
            obj.vel(obj.k) = 0;
            obj.k = 1;
            obj.currentStep = 2;
        end
            
        function obj = step2(obj)
            
            %get max accelerations 
            [velMax, ~, velMaxAcc]  = obj.velMax(obj.pos(obj.k));
            [~, accMax]             = obj.accLim(obj.pos(obj.k), obj.vel(obj.k));   

            
            %calculate new positions and velocities
            if obj.k > 1    
                obj.pos(obj.k) = obj.pos(obj.k-1) + obj.vel(obj.k-1)*obj.dt;
                obj.vel(obj.k) = obj.vel(obj.k-1) + obj.acc(obj.k-1)*obj.dt;
            end
            obj.acc(obj.k) = accMax;
            
            %transitions
            if obj.pos(obj.k) > obj.path.length
                obj.currentStep = 5;
                obj.k = 1;
            elseif obj.vel(obj.k) > velMax
                 obj.currentStep = 3;
            elseif obj.vel(obj.k) > velMaxAcc
                obj.searchPos = obj.pos(obj.k-2);
                obj.lastPos   = obj.pos(obj.k-2);
                obj.currentStep = 4;

            end
            obj.k = obj.k+1;
        end    
        
        function obj = step3(obj)
            [velMax, ~, velMaxAcc] = obj.velMax([obj.pos(obj.k-2), obj.pos(obj.k-1)]);
            [accMin, accMax]  = obj.accLim(obj.pos(obj.k-1), velMax(2));
             %following limit curve
            if obj.k > 1    
                obj.pos(obj.k) = obj.pos(obj.k-1) + obj.vel(obj.k-1)*obj.dt;
                obj.vel(obj.k) = velMax(2);
            end
            
            if accMin/obj.vel(obj.k) > diff(velMaxAcc)/diff([obj.pos(obj.k-1), obj.pos(obj.k)])
                obj.searchPos = obj.pos(obj.k-2);
                obj.lastPos   = obj.pos(obj.k-2);
                obj.currentStep = 4;
            elseif accMax/obj.vel(obj.k) < diff(velMaxAcc)/diff([obj.pos(obj.k-1), obj.pos(obj.k)])
                obj.currentStep = 2;
    
            end
            obj.k = obj.k+1;
        end
        
        function obj = step4(obj)
            switchingPointCandidates = [];

            %VII. A. 1) Caused by Acceleration Constraints and Discontinuous
            foundSwitchingPoint = false;
            
            s = [obj.searchPos:1e-1:obj.path.length]; 
            [velMax, dvelMax, velMaxAcc] = obj.velMax(s);
            [accMin, accMax] = obj.accLim(s, velMax);
            tol = 0.15;
            idx = find((abs(diff(velMaxAcc)) > tol) == 1, 1,"first");
            s(idx)
            sp = s(idx+2);
            sm = s(idx);

            [~, ~, velMaxAccP]            = obj.velMax([s(idx+1), sp]);
            [~, ~, velMacAccM]            = obj.velMax([sm ,s(idx+1)]);
            [~, accMaxP]                  = obj.accLim(sp, velMaxAccP);
            [~, accMaxM]                  = obj.accLim(sm, velMacAccM);

            dvelMaxAccP = diff(velMaxAccP);
            dvelMacAccM = diff(velMacAccM);
            
            velMaxAccP = velMaxAccP(2);
            velMacAccM = velMacAccM(1);

            foundSwitchingPoint = ((velMacAccM < velMaxAccP) & (accMaxM >= dvelMacAccM)) | ((velMacAccM > velMaxAccP) & (accMaxP <= dvelMaxAccP));
            if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idx+2)];
            end
            
            %VII. A. 2) Caused by Acceleration Constraints and Continuous and Nondifferentiable
            foundSwitchingPoint = false;

            idxY = find(diff(sign(obj.dfy(s))) ~= 0, 1, "first");

            if length(idxY) ~= 0 
                sy = fzero(@(s)dfy(s,path), [s(idxY-10) s(idxY+10)]);
                foundSwitchingPoint = length(sy) ~= 0;
            end
             if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idxY+1)];
            end

            
            
             idxX = find(diff(sign(obj.dfx(s))) ~= 0, 1, "first");
            if length(idxX) ~= 0
                sx = fzero(@(s)dfx(s,path), [s(idxX-10) s(idxX+10)])
                foundSwitchingPoint = length(sx) ~= 0;
            end
             if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idxX+1)];
            end

            %VII. A. 2) B. Caused by Velocity Constraints and Continuous
            foundSwitchingPoint = false;

            idx = find(diff(sign(obj.swPointContVel(s))) ~= 0, 1, "first");
            foundSwitchingPoint = length(s(idx+1)) ~= 0;
            if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idx+1)];
            end

            
            %VII. A. 2) B. Caused by Velocity Constraints and Discontinuous
            foundSwitchingPoint = false;
            [ddx, ddy] = obj.path.diff(s, 2);
            tol = 0.3;
            idx = find((abs(diff(ddx)) > tol) == 1, 1,"first");

            [velMaxM, ~, velMaxAccM]         = obj.velMax([s(idx) s(idx+1)]);
            [velMaxP, ~, velMacAccP]         = obj.velMax([s(idx+1) s(idx+2)]);
            [accMinM, ~]                     = obj.accLim(s(idx+1), velMaxM);
            [accMinP, ~]                     = obj.accLim(s(idx+1), velMaxP);

            foundSwitchingPoint = (accMinM >= diff(velMaxAccM)) & (accMinP <= diff(velMacAccP));
            if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idx+1)];
            end

            
            idx = find((abs(diff(ddy)) > tol) == 1, 1,"first");
            [velMaxM, ~, velMaxAccM]         = obj.velMax([s(idx) s(idx+1)]);
            [velMaxP, ~, velMacAccP]         = obj.velMax([s(idx+1) s(idx+2)]);
            [accMinM, ~]                     = obj.accLim(s(idx+1), velMaxM);
            [accMinP, ~]                     = obj.accLim(s(idx+1), velMaxP);
            foundSwitchingPoint = (accMinM >= diff(velMaxAccM)) & (accMinP <= diff(velMacAccP));
            if foundSwitchingPoint
                switchingPointCandidates = [switchingPointCandidates, s(idx+1)];
            end
               
            obj.nextSwitchingPoint = min(switchingPointCandidates);
            obj.currentStep = 5;
            obj.k = 1;
        end
        
        function obj = step5(obj)
            if obj.k == 1
                obj.posBackward = zeros(1000,1); 
                obj.velBackward = zeros(1000,1); 
                
                obj.posBackward(1) = obj.nextSwitchingPoint;
                
                [velMax, ~, velMaxAcc]  = obj.velMax(obj.nextSwitchingPoint);   
                obj.velBackward(1) = min(velMax, velMaxAcc);
            end
           
           [velMax, ~, velMaxAcc]  = obj.velMax(obj.posBackward(obj.k));   
           [accMin, ~]             = obj.accLim(obj.posBackward(obj.k), obj.velBackward(obj.k));   
            %calculate new positions and velocities
            if obj.k > 1    
                obj.posBackward(obj.k) = obj.posBackward(obj.k-1) - obj.velBackward(obj.k-1)*obj.dt;
                obj.velBackward(obj.k) = obj.velBackward(obj.k-1) - obj.acc(obj.k-1)*obj.dt; 
            end
            obj.acc(obj.k) = accMin;
            
            
            idxPos = find(obj.posBackward(obj.k) < obj.pos, 1, "first");
            if obj.velBackward(obj.k) > obj.vel(idxPos)
                obj.pos(idxPos:idxPos+obj.k-2) = flip(obj.posBackward(1:obj.k-1));
                obj.vel(idxPos:idxPos+obj.k-2) = flip(obj.velBackward(1:obj.k-1));
                obj.k = idxPos+obj.k-2;
                obj.currentStep = 2;
            elseif  (obj.velBackward(obj.k) > velMax) ||  (obj.velBackward(obj.k) > velMaxAcc) 
                throw(MException("TrajectoryPlanner:InfeasibleTrajectory","Step 5: Crossed Limit Curves while integrating backward."));
            end
            
            obj.k = obj.k + 1;
            
        end
        
        function y = dfy(obj, s)
            [~, y] = obj.path.diff(s);
        end

        function x = dfx(obj, s)
             [x, ~] = obj.path.diff(s);
        end

        function swPointContVel = swPointContVel(obj, s)
            [valMax, ~, velMaxAcc] = obj.velMax(s);
            [accMin, ~]  = obj.accLim(s, valMax);
            dvelMaxAcc  = diff([0; velMaxAcc]);
            swPointContVel  = accMin -dvelMaxAcc;       
        end
        

    end
end


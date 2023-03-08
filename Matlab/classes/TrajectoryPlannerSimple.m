classdef TrajectoryPlannerSimple
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
        swp
        
        pos  
        vel  
        acc   
        dt   
        k
        j
    end
    
    methods
        
        function obj = TrajectoryPlannerSimple(path, qAccMax, qVelMax)
            obj.path = path;
            obj.qAccMax = qAccMax;
            obj.qVelMax = qVelMax;
            
            obj.searchTol       = 0.2;
            obj.searchStepWidth = 1e-3;
            obj.searchPos       = 0;
            obj.lastPos         = 0;
            
            obj.posBackward    = zeros(10000,1);
            obj.velBackward    = zeros(10000,1);
            
            obj.pos            = zeros(10000,1);
            obj.vel            = zeros(10000,1);
            obj.acc            = zeros(10000,1);
            obj.dt             = [];
            obj.swp            = obj.calculateSWP();
        end
                      
        function obj = generateTrajectory(obj, dt)
        obj.k = 1;
        obj.currentStep = 1;
        obj.dt = dt;
        while obj.pos(obj.k) < obj.path.length
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
                    obj = obj.step5();
                otherwise
                    throw(MException("TrajectoryPlanner:InvalidState","Entered an invalid state"));
            end
            
            if (obj.k > 10000)
                disp("Run out of array elemets")
                break
           end
           end
        
           idx = find(obj.pos ,1,"last")-1; 
           obj.pos = obj.pos(1:idx);
           obj.vel = obj.vel(1:idx);
        end
        
        %velocity limit and its derivative, eq. (36), (37), (31)
        function [velMax, dvelMax, velMaxAcc] = velMax(obj, s) 
            [ddx,ddy]    = obj.path.diff(s,2);
            velMax       = obj.qVelMax*ones(length(s),1);
            dvelMax      = zeros(length(s),1);
            velMaxAcc    = zeros(length(s),1);


            for i=1:length(s)
                if (ddx(i)^2+ddy(i)^2) ~= 0
                    velMaxAcc(i) = min(obj.qVelMax, sqrt(obj.qAccMax/sqrt(ddx(i)^2+ddy(i)^2)));
                else

                    velMaxAcc(i) = obj.qVelMax;
                end
            end
        end
        
        %upper and lower acceleration limit eq. (22), (23)
        function [accMin, accMax] = accLim(obj, s, vel)
               [ddx,ddy]    = obj.path.diff(s,2);
               
               accMin = zeros(length(s),1);
               accMax = zeros(length(s),1);
               
               for i=1:length(s)
                    accMaxSquare = obj.qAccMax^2-vel(i)^4*(ddx(i)^2+ddy(i)^2);
                    if accMaxSquare > -1e-10      
                        accMaxSquare = abs(accMaxSquare);
                        accMin(i) = -sqrt(accMaxSquare);
                        accMax(i) = sqrt(accMaxSquare);
                    else
                        throw(MException("TrajectoryPlannerSimple:ConstraintViolation","Violated velocity constraint caused by acceleration limit."));
                    end
               end
               
               
        end
  
        function obj = step1(obj)
            obj.vel(obj.k) = 0;
            obj.k = 1;
            obj.currentStep = 2;
        end
            
        function obj = step2(obj)

            %calculate new positions and velocities
            if obj.k > 1   
                obj.pos(obj.k) = obj.pos(obj.k-1) + obj.vel(obj.k-1)*obj.dt;
                obj.vel(obj.k) = obj.vel(obj.k-1) + obj.acc(obj.k-1)*obj.dt;
            end
            
            %get max accelerations 
            [velMax, ~, velMaxAcc]  = obj.velMax(obj.pos(obj.k));
            [~, accMax]             = obj.accLim(obj.pos(obj.k), obj.vel(obj.k));   

            obj.acc(obj.k) = accMax;
            
            %transitions
            if obj.pos(obj.k) > obj.path.length
                obj.posBackward    = zeros(10000,1);
                obj.velBackward    = zeros(10000,1);
                obj.currentStep = 5;
                obj.posBackward(1) = obj.path.length;                
                obj.velBackward(1) = 0;
                [accMin, ~] = obj.accLim(obj.path.length, 0);
                obj.acc(1) = accMin;
                obj.k = 1;
            elseif obj.vel(obj.k) > velMax
                 obj.k = obj.k - 1;
                 obj.currentStep = 3;
            elseif obj.vel(obj.k) > velMaxAcc
                obj.searchPos = obj.pos(obj.k-2);
                obj.lastPos   = obj.pos(obj.k-2);
                obj.currentStep = 4;

            end
            obj.k = obj.k+1; 
        end    
        
        function obj = step3(obj)
            [velMax, ~, velMaxAcc] = obj.velMax(obj.pos(obj.k-1));
            vel = min(velMax, velMaxAcc);
            
            [accMin, accMax]  = obj.accLim(obj.pos(obj.k-1), vel);
             %following limit curve
            if obj.k > 1    
                obj.pos(obj.k) = obj.pos(obj.k-1) + obj.vel(obj.k-1)*obj.dt;
                obj.vel(obj.k) = vel;
            end
            dvelMaxAcc = obj.dvelMaxAcc(obj.pos(obj.k));
            
            if obj.pos(obj.k) > obj.path.length
                obj.posBackward    = zeros(10000,1);
                obj.velBackward    = zeros(10000,1);
                obj.currentStep = 5;
                obj.posBackward(1) = obj.path.length;                
                obj.velBackward(1) = 0;
                [accMin, ~] = obj.accLim(obj.path.length, 0);
                obj.acc(1) = accMin;
                obj.k = 1;
            elseif accMin/obj.vel(obj.k) > dvelMaxAcc
                obj.searchPos = obj.pos(obj.k-2);
                obj.lastPos   = obj.pos(obj.k-2);
                obj.currentStep = 4;
            elseif accMax/obj.vel(obj.k) < dvelMaxAcc
                obj.currentStep = 2;
            end
            obj.k = obj.k+1;
        end
        
        function obj = step4(obj)
            idx = find(((obj.swp - obj.searchPos) > 0) == 1, 1, "first");
            obj.nextSwitchingPoint = obj.swp(idx);
            
            obj.posBackward = zeros(1000,1); 
            obj.velBackward = zeros(1000,1); 
                        
            obj.posBackward(1) = obj.nextSwitchingPoint;                
            [velMax, ~, velMaxAcc]  = obj.velMax(obj.nextSwitchingPoint);   
            obj.velBackward(1) = min(velMax, velMaxAcc);

            [accMin, ~] = obj.accLim(obj.posBackward(1), obj.velBackward(1));
            obj.acc(1) = accMin;
            
            obj.k = 2;
            
            obj.currentStep = 5;
        end
        
        function obj = step5(obj)
            %calculate new position
            obj.posBackward(obj.k) = obj.posBackward(obj.k-1) - obj.velBackward(obj.k-1)*obj.dt;           
            obj.velBackward(obj.k) = obj.velBackward(obj.k-1) - obj.acc(obj.k-1)*obj.dt; 

            [accMin, ~]             = obj.accLim(obj.posBackward(obj.k), obj.velBackward(obj.k)); 
            obj.acc(obj.k) = accMin;

            [velMax, ~, velMaxAcc]  = obj.velMax(obj.posBackward(obj.k));   
            idxPos = find(obj.posBackward(obj.k) < obj.pos, 1, "first");
            if obj.velBackward(obj.k) > obj.vel(idxPos)
                obj.pos(idxPos:idxPos+obj.k-2) = flip(obj.posBackward(1:obj.k-1));
                obj.vel(idxPos:idxPos+obj.k-2) = flip(obj.velBackward(1:obj.k-1));
              
                obj.k = idxPos+obj.k-2;
                [velMax, ~, velMaxAcc]  = obj.velMax(obj.pos(obj.k));   
                [~, accMax] = obj.accLim(obj.pos(obj.k), min(velMax, velMaxAcc));
                obj.acc(obj.k) = accMax;
                
                obj.currentStep = 2;
                
             elseif  (abs(obj.velBackward(obj.k)-velMax) < 1e-16) ||  (abs(obj.velBackward(obj.k) - velMaxAcc) < 1e-16) 
                 abs(obj.velBackward(obj.k)-velMax)
                 abs(obj.velBackward(obj.k) - velMaxAcc)
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
      
        function dvelMaxAcc = dvelMaxAcc(obj, s, order)
          if ~exist("order","var")
              order = 1;
          end
          
          ds  = 1e-6;
          if order == 1
             [~, ~, velMaxAcc] = obj.velMax([s-ds, s+ds]);
             dvelMaxAcc = diff(velMaxAcc)/(2*ds);
          elseif order == 2   
             [~, ~, velMaxAcc] = obj.velMax([s-ds, s,s+ds]);
             dvelMaxAcc = diff(diff(velMaxAcc)/(ds))/ds;
          end
        end
        
        function swp = calculateSWP(obj)
        t  = obj.path.getDiscontinuousSwitchtingPointCandidate();
        swp = [];
            for i = 1:2:length(t)
                ds = diff(t(i:i+1))*0.45;
                s0 = fzero(@(s)obj.dvelMaxAcc(s,1), [t(i)+ds, t(i+1)-ds]);
                if abs(obj.dvelMaxAcc(s0,2)) > 1e-6
                    swp = [swp;s0];
                end
            end
          swp = sort(swp);
        end     
        
        function plotVelLimPhasePlane(obj, trajectory)
            if ~exist("trajectory","var")
                trajectory = false;
            end
            
            s = [0:.01:obj.path.length];
            [velMax, ~, velMaxAcc] = obj.velMax(s);
            
            figure()
            plot(s, velMax);
            hold on;
            grid minor;
            plot(s, velMaxAcc);
            
            if trajectory
                plot(obj.pos, obj.vel);
            end
            title("$s$-$\dot{s}$ Phase Portrait","interpreter", "latex")
            xlabel("$s$","interpreter","latex", "fontsize", 18);
            ylabel("$\dot{s}$","interpreter","latex","fontsize", 18);
            
            if trajectory
                legend(["Vel. Lim", "Acc. Lim", "Vel."],"interpreter","latex");
            else
                legend(["Vel. Lim", "Acc. Lim"],"interpreter","latex");
            end
        end
        
        function plotTrajectoryOverTime(obj)

        figure()
        t = [0:length(obj.pos)-1]*obj.dt;

        subplot(3,1,1);
        plot(t,obj.pos,":x")
        hold on;
        grid minor;
        title("Trajectory over time","interpreter","latex", "fontsize", 24)

        xlim([min(t) max(t)])
        ylabel("$s(t)$","interpreter","latex", "fontsize", 18);

        
        
        subplot(3,1,2);
        plot(t,obj.vel,":x")
        hold on;
        grid minor;
        xlim([min(t) max(t)])
        ylabel("$\dot{s}(t)$","interpreter","latex", "fontsize", 18);

                
        subplot(3,1,3);
        plot(t, diff([0;obj.vel])/obj.dt,":x")
        hold on;
        grid minor;
        xlim([min(t) max(t)])
        xlabel("$t$","interpreter","latex", "fontsize", 18);
        ylabel("$\ddot{s}(t)$","interpreter","latex", "fontsize", 18);



        end
    end
end


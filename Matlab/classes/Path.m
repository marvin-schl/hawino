classdef Path < Spline
    properties
        %startPoint
        %endPoint
        transitions
        subsplines
    end
    
    methods 
        function obj = Path(x,y,r)
           [x, y] = obj.preprocessWaypointlist(x,y)
           nmbSubSplines = 2*length(x)-3;
           subsplines   = Spline.empty(nmbSubSplines,0);
           obj.transitions  = zeros(length(obj.subsplines)-1,1);
           
           %generate bezier curves
           for i = 2:2:nmbSubSplines-1
               subsplines(i) = BezierCurve(x(i/2:i/2+2),y(i/2:i/2+2),r);
           end
           
           %generate first linear
           subsplines(1) = LinearSpline(...
                            [x(1),subsplines(2).startPoint.x],...
                            [y(1),subsplines(2).startPoint.y]);
                        
           %generate last linear
           subsplines(nmbSubSplines) = LinearSpline(...
                        [subsplines(nmbSubSplines-1).endPoint.x, x(length(x))],...
                        [subsplines(nmbSubSplines-1).endPoint.y, y(length(y))]);

           %generate linears in between
           for i = 3:2:nmbSubSplines-2
                x = [subsplines(i-1).endPoint.x,subsplines(i+1).startPoint.x];
                y = [subsplines(i-1).endPoint.y,subsplines(i+1).startPoint.y];
                subsplines(i) = LinearSpline(x,y);
           end
           
           obj.subsplines = subsplines;
           obj.length = obj.calculateLength();
           obj.transitions = obj.calculateTransitions();
           
           obj.startPoint = struct("x", x(1), "y", y(1), "phi", subsplines(1).startPoint.phi);
           obj.endPoint =  struct("x", x(length(x)), "y", y(length(y)), "phi", obj.subsplines(length(obj.subsplines)).endPoint.phi);      
        end
        
        function [x, y, phi] = getPoint(obj, s)
            [idx, s_offset] = obj.getSubsplineToPoint(s);
            x   = zeros(length(s),1);
            y   = zeros(length(s),1);
            phi = zeros(length(s),1);

            for i = 1:length(idx)
                [x(i),y(i)] = obj.subsplines(idx(i)).getPoint(s_offset(i));
                deltaPhi = obj.endPoint.phi - obj.startPoint.phi;
                phi(i)   = obj.startPoint.phi+deltaPhi/2*(1-cos(pi/obj.length*s(i)));
            end
        end
        
        function [x,y, phi] = diff(obj, s, order)
           if (~exist("order","var"))
               order = 1;
           end
            
            x = zeros(length(s),1);
            y = zeros(length(s),1);
            phi = zeros(length(s),1);
            [idx, s_offset] = obj.getSubsplineToPoint(s);
            for i = 1:length(idx)                 
                [x(i),y(i)] = obj.subsplines(idx(i)).diff(s_offset(i), order);
                deltaPhi = obj.endPoint.phi - obj.startPoint.phi;
                if order == 1
                    phi(i) = deltaPhi*pi/(2*obj.length)*sin(pi/obj.length*s(i));
                elseif order == 2
                    phi(i) = deltaPhi*pi^2/(2*obj.length^2)*cos(pi/obj.length*s(i));
                end
            end
        end
        
        function s = getDiscontinuousSwitchtingPointCandidate(obj)
            s = obj.transitions(2:length(obj.transitions)-1);
        end
        
        function s = getContinousSwitchingPointCandiate(obj, ds)
            if ~exist("ds","var")
                ds = 0.1;
            end
            
            sPath = [0:ds:obj.length];
            
            %search f
            idxY = find((diff(sign(obj.dfy(sPath))) ~= 0) == 1);
            idxX = find((diff(sign(obj.dfx(sPath))) ~= 0) == 1);
            
            s = [];
            if ~isempty(idxX)
                for idx = idxX
                   sm = sPath(idx)-2*ds;
                   sp = sPath(idx)+2*ds;
                   s0 = fzero(@(s) obj.dfx(s), [sm sp]); 
                   if ~isempty(s0)
                       s = [s;s0];
                   end
                end
            end
            
            if ~isempty(idxY) 
               for idx = idxY
                   sm = sPath(idx)-2*ds;
                   sp = sPath(idx)+2*ds;
                   s0 = fzero(@(s) obj.dfy(s), [sm sp]); 
                   if ~isempty(s0) ~= 0
                       s = [s;s0];
                   end
                end
            end


        end
    end
    
    methods (Access = private)
        function [idx, s_offset] = getSubsplineToPoint(obj, s)
            idx = zeros(length(s),1);
            s_offset = zeros(length(s),1);
            for i=1:length(s)
                idx(i) = 1;
                s_offset(i) = s(i);
                while s_offset(i) - obj.subsplines(idx(i)).length() > 0 && idx(i) < length(obj.subsplines)
                    s_offset(i) = s_offset(i) - obj.subsplines(idx(i)).length;
                    idx(i) = idx(i) + 1;
                end
                
                
            end
        end
        
        function t = calculateTransitions(obj)    
            t = zeros(length(obj.subsplines)-1,1);
            for i = 1:length(obj.subsplines)
                t(i+1,1) = t(i,1) + obj.subsplines(i).getLength();
            end
        end
        
        function [x, y] = preprocessWaypointlist(obj, xwpl, ywpl)
        x = [xwpl(1)];
        y = [ywpl(1)];
        for i=2:length(xwpl)-1
            phi1 = atan2(ywpl(i)-ywpl(i-1),xwpl(i)-xwpl(i-1));
            phi2 = atan2(ywpl(i+1)-ywpl(i),xwpl(i+1)-xwpl(i));
            if phi1 ~= phi2
                x = [x, xwpl(i)];
                y = [y, ywpl(i)];
            end
        end
        x = [x, xwpl(length(xwpl))];
        y = [y, ywpl(length(ywpl))];
        end
        
        function y = dfy(obj,s)
            [~, y, ~] = obj.diff(s, 1);
        end

        function x = dfx(obj, s)
             [x, ~, ~] = obj.diff(s, 1);
        end
             
    end
    
    methods (Access = protected)
        function len = calculateLength(obj)
            len = 0;
            for i = 1:length(obj.subsplines)
                len = len + obj.subsplines(i).getLength();
            end
        end
    end     
   
end

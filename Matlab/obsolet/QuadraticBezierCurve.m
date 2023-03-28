classdef QuadraticBezierCurve < BezierCurve
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        controlPoint        % Control point of the Bezier curve [x, y]
        ax, bx, cx
        ay, by, cy
        r                   % Radius of Bezier curve
        dt                  % Sampling distance for only length calculation
        maxAbsCurvature
    end
    
    methods
        function obj = QuadraticBezierCurve(x, y, r, dt)
            if (~exist("dt","var"))
                dt = 1e-3;
            end     
            
            obj = obj@BezierCurve(x,y);
    
           % Initializations
            prevWP = struct("x", x(1), "y", y(1));
            nextWP = struct("x", x(3), "y", y(3));
            obj.controlPoint = struct("x", x(2), "y", y(2));
            obj.r = r;
            obj.dt = dt;
            % 1.) Calculate start- and end point of curve (intersections of
            % linear waypoint connections with circle around control point)
            [obj.startPoint, obj.endPoint] = obj.getStartEndPoint(prevWP, nextWP);
            
            % 2.) calculate coefficients
            [obj.ax, obj.bx, obj.cx, obj.ay, obj.by, obj.cy] = obj.calculateCoefficients();
            
            % 3.) Calculate length of curve
            obj = obj.calculateLength();
            
            %[ddx, ddy] = obj.diff([0:dt:obj.length],2);
            %obj.maxAbsCurvature = struct("x", max(abs(ddx)), "y", max(abs(ddy)));
        end
    end
    
      methods (Access=protected)
        function [x,y] = getPointNorm(obj, t)
            % calculate corresponding point(s) (hard-coded for 3rd order Bezier curve)
            x = obj.ax*t.^2 + obj.bx * t + obj.cx;
            y = obj.ay*t.^2 + obj.by * t + obj.cy;
        end
        
        
        function [dx,dy] = diffNorm(obj,t)
            % calculate corresponding derivative at point(s) (hard-coded for 3rd order Bezier curve)
            dx = 2*obj.ax*t + obj.bx;
            dy = 2*obj.ay*t + obj.by;
        end
      
        function [ddx, ddy] = diff2Norm(obj,t)
            ddx = 2*obj.ax;
            ddy = 2*obj.ay;
        end
      
     function s = s(obj, t) 
            %matlab symbolic integration of: sqrt((dx/dt)^2+(dy/dt)^2)
            sIn = @(t)( (t/2 + (4*obj.ax*obj.bx + 4*obj.ay*obj.by)/(4*(4*obj.ax^2 + 4*obj.ay^2)))*(t*(4*obj.ax*obj.bx + 4*obj.ay*obj.by) ...
                + obj.bx^2 + obj.by^2 + t^2*(4*obj.ax^2 + 4*obj.ay^2))^(1/2) ...
               - (log((2*obj.ax*obj.bx + 2*obj.ay*obj.by + t*(4*obj.ax^2 + 4*obj.ay^2))/(4*obj.ax^2 + 4*obj.ay^2)^(1/2) ...
               + (t*(4*obj.ax*obj.bx + 4*obj.ay*obj.by) + obj.bx^2 + obj.by^2 ...
               + t^2*(4*obj.ax^2 + 4*obj.ay^2))^(1/2))*((4*obj.ax*obj.bx + 4*obj.ay*obj.by)^2/4 ...
               - (4*obj.ax^2 + 4*obj.ay^2)*(obj.bx^2 + obj.by^2)))/(2*(4*obj.ax^2 + 4*obj.ay^2)^(3/2)));

            s = sIn(t)-sIn(0);
        end
      
    
      function dds = dds(obj,t, ds)
         if(~exist("ds","var"))
             ds = obj.ds(t);
         end
          
        dds  = (4*(obj.ax^2+obj.ay^2)*t + 2*(obj.ax*obj.bx+obj.ay*obj.by))./ds;
      end
     
      end
     
     methods (Access = private)

         
        function [startPoint, endPoint] = getStartEndPoint(obj, prevWP, nextWP)
            % Start point:
            % - angle of incidence of former linear part
            phi1 = atan2(prevWP.y - obj.controlPoint.y, prevWP.x - obj.controlPoint.x);
            
            % - x-coordinates where former linear part intersects with circle
            zpx11 = obj.controlPoint.x - obj.r * cos(phi1);
            zpx12 = obj.controlPoint.x + obj.r * cos(phi1);
            % - y-coordinates where former linear part intersects with circle
            zpy11 = obj.controlPoint.y - obj.r * sin(phi1);
            zpy12 = obj.controlPoint.y + obj.r * sin(phi1);
            
            % - decide which of the 2 solutions the relevant one
            % (left or right intersection)
            if prevWP.x < obj.controlPoint.x
                zpx1 = min(zpx11, zpx12);
            else
                zpx1 = max(zpx11, zpx12);
            end

            if prevWP.y < obj.controlPoint.y
                zpy1 = min(zpy11, zpy12);
            else
                zpy1 = max(zpy11, zpy12);
            end
            
            % ZP 2:
            % - angle of incidence of following linear part
            phi2 = atan2(nextWP.y - obj.controlPoint.y, nextWP.x - obj.controlPoint.x);

            % - x-coordinates where following linear part intersects with circle
            zpx21 = obj.controlPoint.x - obj.r * cos(phi2);
            zpx22 = obj.controlPoint.x + obj.r * cos(phi2);
            % - y-coordinates where former linear part intersects with circle
            zpy21 = obj.controlPoint.y - obj.r * sin(phi2);
            zpy22 = obj.controlPoint.y + obj.r * sin(phi2);

            % - decide which of the 2 solutions the relevant one
            % (left or right intersection)
            if nextWP.x < obj.controlPoint.x
                zpx2 = min(zpx21, zpx22);
            else
                zpx2 = max(zpx21, zpx22);
            end

            if nextWP.y < obj.controlPoint.y
                zpy2 = min(zpy21, zpy22);
            else
                zpy2 = max(zpy21, zpy22);
            end

            startPoint.x = zpx1;
            startPoint.y = zpy1;
            endPoint.x = zpx2;
            endPoint.y = zpy2;
          end
    % -----------------------------------------------------------------
        function [ax, bx, cx, ay, by, cy] = calculateCoefficients(obj)
            ax = (obj.startPoint.x - 2*obj.controlPoint.x + obj.endPoint.x);
            bx = (2*obj.controlPoint.x - 2*obj.startPoint.x);
            cx = obj.startPoint.x;
            
            ay = (obj.startPoint.y - 2*obj.controlPoint.y + obj.endPoint.y);
            by = (2*obj.controlPoint.y - 2*obj.startPoint.y);
            cy = obj.startPoint.y;
           
       end   
    
    end
    
end


classdef BezierCurve < Spline
    % P U B L I C  P R O P E R T I E S ====================================
    properties
        startPoint          % Entry point of the Bezier curve [x, y]
        endPoint            % Exit point of the Bezier curve [x, y]
        maxAbsCurvature
        controlPoint        % Control point of the Bezier curve [x, y]
        ax, bx, cx
        ay, by, cy
        r                   % Radius of Bezier curve
        dt                  % Sampling distance for only length calculation
    end

    
    
    % P R I V A T E  P R O P E R T I E S ==================================


    % P U B L I C  M E T H O D S ==========================================
    methods
        % -----------------------------------------------------------------
        % FUNCTION: BezierCurve(x, y, r, dx)
        % Constructor
        % Inputs:   
        %   [x]     x-coordinates of previous WP, control point, next WP
        %   [y]     y-coordinates of previous WP, control point, next WP
        %   r       radius of Bezier circle with respect to control
        %   dx      sampling distance
        % Outputs:  none
        function obj = BezierCurve(x, y, r, dt)
            if (~exist("dt","var"))
                dt = 1e-3;
            end     
                
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
            
            [ddx, ddy] = obj.diff([0:dt:obj.length],2);
            obj.maxAbsCurvature = struct("x", max(abs(ddx)), "y", max(abs(ddy)));
        end
        % -----------------------------------------------------------------

        % -----------------------------------------------------------------
        % FUNCTION: getPoint(s)
        % Returns either a corresponding point for a given scalar parameter
        % or an array of points for a given parameter vector. Parameter s
        % can be normalized (s = [0 : dx : 1]) or absolute (s = [0 : dx :
        % length(curve)]
        % Inputs:   
        %   [s]             parameter: scalar or vector, normalized or absolute
        %   isNormalized    has to be set true, if s shall be interpreted 
        %                   as normalized value. Otherwise it can be
        %                   neglected in method call.
        % Outputs:
        %   [x, y]          corresponding point (array of points) for parameter (vector)
        function [x,y] = getPoint(obj, s)
            t = obj.normalize(s);
            [x,y] = obj.getPointNorm(t);
        end
        % -----------------------------------------------------------------
        
        % -----------------------------------------------------------------
        % FUNCTION diff:
        % Computes derivate of function at point/interval s
        %Inputs:
        %   [s]     parameter: scalar or vector
        % Outputs:
        %   [x, y]          corresponding derivative (array of points) for parameter (vector)
        function [dx,dy] = diff(obj, s, order)
           if (~exist("order","var"))
               order = 1;
           end
            t = obj.normalize(s); %t(s)
            [dx,dy] = obj.diffNorm(t);
            ds          = obj.ds(t);      
           switch order
               case 1
                   %calculate first derivative
                   %inner derivative
                    dx = dx*1./ds;
                    dy = dy*1./ds;
               case 2
                    dds         = obj.dds(t, ds);        %d^2/dt^2 s(t)
                    [ddx, ddy]  = obj.diff2Norm(t);  %d/dt gamma(t)
                    
                    %calculate second derivate, derivation not trivial
                    dx = ddx.*ds.^-2 - dx .* ds.^-3 .* dds;
                    dy = ddy.*ds.^-2 - dy .* ds.^-3 .* dds;
               otherwise   
                    throw(MException("BezierCurve:DerivativeNotImplemented", sprintf("Derivative of order %d not implemnted.",order)));

           end
        end
        % -----------------------------------------------------------------
        

        % -----------------------------------------------------------------
        

        
        % -----------------------------------------------------------------
        
        
    end

    % P R I V A T E  M E T H O D S ========================================
    methods (Access = private)
        % -----------------------------------------------------------------
        % FUNCTION: getStartEndPoint(prevWP, nextWP)
        % Returns corresponding start- and end points for a given previous
        % and following waypoint. The middle waypoint is the control point
        % of the curve. The start- and end points are the intersections of
        % the linear waypoint connections and a circle with radius r around
        % the control point. Start- and end points are the connection 
        % points of linear and Bezier splines.
        % Inputs:
        %   prevWP      previous waypoint [x, y]
        %   nextWP      next waypoint [x, y]
        % Outputs:
        %   startPoint  start point of curve [x, y]
        %   endPoint    end point of curve [x, y]
  
        function ds = ds(obj,t)
            [dx, dy] = obj.diffNorm(t);
            ds = sqrt(dx.^2+dy.^2);
        end


        function t = normalize(obj,s0)
            t = zeros(length(s0),1);
            for i=1:length(s0)
                    t_prev = 2;
                    while abs(t(i)-t_prev) > 1e-4
                        t_prev = t(i);
                        t(i) = t(i) - (obj.s(t(i)) - s0(i)) / obj.ds(t(i));
                    end
            end
        end
        
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

    % P R O T E C T E D  M E T H O D S ====================================
    methods (Access = protected)
        % -----------------------------------------------------------------
        % FUNCTION: calculateLength()
        % Calculates the curve length
        % Inputs:   none
        % Outputs:  none
        function  obj = calculateLength(obj)
            t = [0:obj.dt:1 - obj.dt];
            obj.length = sum(obj.ds(t)*obj.dt);
        end
        % -----------------------------------------------------------------
        
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

end
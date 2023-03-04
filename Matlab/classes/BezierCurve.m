classdef BezierCurve < Spline
    % P U B L I C  P R O P E R T I E S ====================================
    properties
        startPoint          % Entry point of the Bezier curve [x, y]
        endPoint            % Exit point of the Bezier curve [x, y]
    end

    
    
    % P R I V A T E  P R O P E R T I E S ==================================
    properties (Abstract)
      
    end
    
    methods (Abstract, Access=protected)
        getPointNorm
        diffNorm
        diff2Norm
        s
        dds
    end

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
        function obj = BezierCurve(x, y)

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
    end

end
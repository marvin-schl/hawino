classdef BezierCurve < Spline
    % P U B L I C  P R O P E R T I E S ====================================
    properties
        startPoint          % Entry point of the Bezier curve [x, y]
        endPoint            % Exit point of the Bezier curve [x, y]
        r                   % Radius of Bezier curve
        ds                  % Sampling distance
        curvePoints         % array of curve points [x1, y1; ...; xn, yn]
    end

    % P R I V A T E  P R O P E R T I E S ==================================
    properties (Access = private)
        controlPoint        % Control point of the Bezier curve [x, y]
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
        function obj = BezierCurve(x, y, r, ds)
            % Initializations
            prevWP = struct("x", x(1), "y", y(1));
            nextWP = struct("x", x(3), "y", y(3));
            obj.controlPoint = struct("x", x(2), "y", y(2));
            obj.r = r;
            obj.ds = ds;
            obj.startPoint = struct("x", 0, "y", 0);
            obj.endPoint = struct("x", 0, "y", 0);

            % 1.) Calculate start- and end point of curve (intersections of
            % linear waypoint connections with circle around control point)
            [obj.startPoint, obj.endPoint] = obj.getStartEndPoint(prevWP, nextWP);

            % 2.) Calculate all points on curve and save as struct
            % (all points on parameter interval s = 0 : dx : 1)
            [curvePointsX, curvePointsY] = obj.getPoint([0 : ds : 1], true);
            obj.curvePoints = struct("x", curvePointsX, "y", curvePointsY);

            % 3.) Calculate length of curve
            obj = obj.calculateLength();
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
        function [x,y] = getPoint(obj, s, isNormalized)
            % normalize parameter if required
            if ~exist('isNormalized', 'var')
                isNormalized = false;
            end
 
            if ~isNormalized
                t = s/obj.length;
            else
                t = s;
            end
            
            % calculate corresponding point (hard-coded for 3rd order Bezier curve)
            x = (obj.startPoint.x - 2*obj.controlPoint.x + obj.endPoint.x)*t.^2 + (2*obj.controlPoint.x - 2*obj.startPoint.x) * t + obj.startPoint.x;
            y = (obj.startPoint.y - 2*obj.controlPoint.y + obj.endPoint.y)*t.^2 + (2*obj.controlPoint.y - 2*obj.startPoint.y) * t + obj.startPoint.y;
        end
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
    end

    % P R O T E C T E D  M E T H O D S ====================================
    methods (Access = protected)
        % -----------------------------------------------------------------
        % FUNCTION: calculateLength()
        % Calculates the curve length
        % Inputs:   none
        % Outputs:  none
        function  obj = calculateLength(obj)
            obj.length = sum(sqrt(diff(obj.curvePoints.x).^2 + diff(obj.curvePoints.y).^2));
        end
        % -----------------------------------------------------------------
    end
end
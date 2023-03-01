classdef bezierCurve
    properties
        startPoint          % Entry point of the Bezier curve [x, y]
        endPoint            % Exit point of the Bezier curve [x, y]
        r                   % Radius of Bezier curve
        length              % Length of the Bezier curve
        dx                  % Sampling distance
        curvePoints         % array of curve points [x1, y1; ...; xn, yn]
    end

    properties (Access = private)
        controlPoint        % Control point of the Bezier curve [x, y]
        prevWP              % Previous waypoint [x, y]
        nextWP              % y-coordinates of three waypoints [x, y]
    end

    methods 
        function obj = bezierCurve(wp, r, dx)
            obj.prevWP = struct("x", wp(1, 1), "y", wp(1, 2));
            obj.controlPoint = struct("x", wp(2, 1), "y", wp(2, 2));
            obj.nextWP = struct("x", wp(3, 1), "y", wp(3, 2));
            obj.r = r;
            obj.dx = dx;
            obj.startPoint = struct("x", 0, "y", 0);
            obj.endPoint = struct("x", 0, "y", 0);

            [obj.startPoint, obj.endPoint] = obj.getStartEndPoint();
            obj.curvePoints = obj.getCurvePoints(obj.startPoint, obj.controlPoint, obj.endPoint, obj.dx);
            obj.length = obj.getLength(obj.curvePoints);
        end

        function [startPoint, endPoint] = getStartEndPoint(obj)
            % Start point:
            % - angle of incidence of former linear part
            phi1 = atan2(obj.prevWP.y - obj.controlPoint.y, obj.prevWP.x - obj.controlPoint.x);
            
            % - x-coordinates where former linear part intersects with circle
            zpx11 = obj.controlPoint.x - obj.r * cos(phi1);
            zpx12 = obj.controlPoint.x + obj.r * cos(phi1);
            % - y-coordinates where former linear part intersects with circle
            zpy11 = obj.controlPoint.y - obj.r * sin(phi1);
            zpy12 = obj.controlPoint.y + obj.r * sin(phi1);
        
            % - decide which of the 2 solutions the relevant one 
            % (left or right intersection)
            if obj.prevWP.x < obj.controlPoint.x
                zpx1 = min(zpx11, zpx12);
            else
                zpx1 = max(zpx11, zpx12);
            end
        
            if obj.prevWP.y < obj.controlPoint.y
                zpy1 = min(zpy11, zpy12);
            else
                zpy1 = max(zpy11, zpy12);
            end
        
            % ZP 2:
            % - angle of incidence of following linear part
            phi2 = atan2(obj.nextWP.y - obj.controlPoint.y, obj.nextWP.x - obj.controlPoint.x);
        
            % - x-coordinates where following linear part intersects with circle
            zpx21 = obj.controlPoint.x - obj.r * cos(phi2);
            zpx22 = obj.controlPoint.x + obj.r * cos(phi2);
            % - y-coordinates where former linear part intersects with circle
            zpy21 = obj.controlPoint.y - obj.r * sin(phi2);
            zpy22 = obj.controlPoint.y + obj.r * sin(phi2);
        
            % - decide which of the 2 solutions the relevant one 
            % (left or right intersection)
            if obj.nextWP.x < obj.controlPoint.x
                zpx2 = min(zpx21, zpx22);
            else
                zpx2 = max(zpx21, zpx22);
            end
        
            if obj.nextWP.y < obj.controlPoint.y
                zpy2 = min(zpy21, zpy22);
            else
                zpy2 = max(zpy21, zpy22);
            end
        
            startPoint.x = zpx1;
            startPoint.y = zpy1;
            endPoint.x = zpx2;
            endPoint.y = zpy2;
        end

        function curvePoints = getCurvePoints(obj, startPoint, controlPoint, endPoint, dx)
            n = 3;
            n1 = n - 1;
            
            for i = 0 : 1 : n1
                sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
            end
            
            l = [];
            UB = [];
            
            for u = 0 : dx : 1
                for d = 1 : n
                    UB(d) = sigma(d)*((1-u)^(n-d))*(u^(d-1));
                end
                
                l = cat(1,l,UB);                                       
            end
            
            curvePoints = l * [startPoint.x, startPoint.y; controlPoint.x, controlPoint.y; endPoint.x, endPoint.y];
        end

        function length = getLength(obj, curvePoints) 
            length = sum(sqrt(diff(curvePoints(:,1)).^2 + diff(curvePoints(:,2)).^2));
        end

        function point = getPoint(obj, s)
            n = 3;
            n1 = n - 1;
            
            for i = 0 : 1 : n1
                sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
            end
            
            l = [];
            UB = [];
            
            s = s / obj.length;

            if ((s < 0) || (s > 1))
                disp("Invalid parameter range! Epected s in range [0 ... obj.length]")
                point = [-1, -1; -1, -1; -1, -1];
            else
                for d = 1 : n
                    UB(d) = sigma(d) * ((1 - s)^(n - d))*(s^(d - 1));
                end
                
                l = cat(1, l, UB);                                       
                
                point = l * [obj.startPoint.x, obj.startPoint.y; obj.controlPoint.x, obj.controlPoint.y; obj.endPoint.x, obj.endPoint.y];
            end
        end

    end
     

    methods (Access = private)  
    end
end
classdef BezierCurve < Spline
    properties
        startPoint          % Entry point of the Bezier curve [x, y]
        endPoint            % Exit point of the Bezier curve [x, y]
        r                   % Radius of Bezier curve
        dx                  % Sampling distance
        curvePoints         % array of curve points [x1, y1; ...; xn, yn]
    end

    properties (Access = private)
        controlPoint        % Control point of the Bezier curve [x, y]
    end

    methods 
        function obj = BezierCurve(x, y, r, dx)
            
            prevWP = struct("x", x(1), "y", y(1));
            nextWP = struct("x", x(3), "y", y(3));      
            obj.controlPoint = struct("x", x(2), "y", y(2));
    
            obj.r = r;
            obj.dx = dx;
            obj.startPoint = struct("x", 0, "y", 0);
            obj.endPoint = struct("x", 0, "y", 0);

            [obj.startPoint, obj.endPoint] = obj.getStartEndPoint(prevWP, nextWP);
            [xCurve,yCurve] = obj.getPoint([0:dx:1]);
            obj.curvePoints = struct("x", xCurve, "y", yCurve);
            obj.length = obj.calculateLength();
           
        end
        
        function curvePoints = getCurvePoints(obj, startPoint, controlPoint, endPoint, dx)
%             n = 3;
%             n1 = n - 1;
%             
%             for i = 0 : 1 : n1
%                 sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
%             end
%             
%             l = [];
%             UB = [];
%             
%             for u = 0 : dx : 1
%                 for d = 1 : n
%                     UB(d) = sigma(d)*((1-u)^(n-d))*(u^(d-1));
%                 end
%                 
%                 l = cat(1,l,UB);                                       
%             end
%             
%             curvePoints = l * [startPoint.x, startPoint.y; controlPoint.x, controlPoint.y; endPoint.x, endPoint.y];
            
        end

        function [x,y] = getPoint(obj, s)
            n = 3;
            n1 = n - 1;
            
            for i = 0 : 1 : n1
                sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
            end
            
            l = [];
            UB = [];
            
             %s = s / obj.length;
             if max(s) ~= 1
                   s = s/obj.length;
             end

            %if any((s < 0)) || any((s > 1))
               % throw(MException("BezierCurve:NotDefined","Invalid parameter range! Expected s in range [0 ... obj.length]"))
            %else
            if true
                for i = 1:length(s)
                    u = s(i);
                    for d = 1 : n
                        UB(d) = sigma(d) * ((1 - u)^(n - d))*(u^(d - 1));
                    end

                    l = cat(1, l, UB);                                       
                end
                point = l * [obj.startPoint.x, obj.startPoint.y; obj.controlPoint.x, obj.controlPoint.y; obj.endPoint.x, obj.endPoint.y];
                x = point(:,1);
                y = point(:,2);
            end
%            t = s;
%            if max(s) ~= 1
%                t = s/obj.length;
%            end
% 
%            x = (obj.startPoint.x - 2*obj.controlPoint.x + obj.endPoint.x)*t.^2 + (2*obj.controlPoint.x - 2*obj.startPoint.x) * t + obj.startPoint.x;
%            y = (obj.startPoint.y - 2*obj.controlPoint.y + obj.endPoint.y)*t.^2 + (2*obj.controlPoint.y - 2*obj.startPoint.y) * t + obj.startPoint.y;
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
        
    end

    
    methods (Access = protected)
                
        function len = calculateLength(obj)
            len = sum(sqrt(diff(obj.curvePoints.x).^2 + diff(obj.curvePoints.y).^2));
        end
    end
end
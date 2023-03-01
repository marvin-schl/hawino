classdef LinearSpline < Spline

    properties
       startPoint
       endPoint 
    end
    
    properties (Access = private)
        m
    end
    

    methods 
        function obj = LinearSpline(x,y)
            obj.startPoint = struct("x", x(1), "y", y(1));
            obj.endPoint   = struct("x", x(2), "y", y(2));
            if x(1) ~= x(2)
                obj.m = diff(y)/diff(x);
            end   
            obj.length = obj.calculateLength();
        end
        
        function [x,y] = getPoint(obj, s)
            if  obj.startPoint.x == obj.endPoint.x
              dy = s;
              dx = 0;
            else
              dx = cos(atan(obj.m)).*s;
              dy = sqrt(s.^2-dx.^2);
            end
            y = obj.startPoint.y + sign(obj.endPoint.y-obj.startPoint.y).*dy;
            x = obj.startPoint.x + sign(obj.endPoint.x-obj.startPoint.x).*dx;
        end   
        
    end
    
    methods( Access = protected)
         function len = calculateLength(obj)
            len = sqrt((obj.startPoint.x - obj.endPoint.x)^2+(obj.startPoint.y - obj.endPoint.y)^2);
         end
    end
end
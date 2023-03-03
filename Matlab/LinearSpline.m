classdef LinearSpline < Spline

    properties
       startPoint
       endPoint 
       phi
    end
    
    properties (Access = private)
        
    end   

    methods 
        function obj = LinearSpline(x,y)
            obj.startPoint = struct("x", x(1), "y", y(1));
            obj.endPoint   = struct("x", x(2), "y", y(2));
            obj.phi        = atan2(obj.endPoint.y-obj.startPoint.y, obj.endPoint.x-obj.startPoint.x);
            obj.length     = obj.calculateLength();
        end
        
        function [x,y] = getPoint(obj, s)
         
            dx = cos(obj.phi).*s;
            dy = sin(obj.phi).*s;
            
            y = obj.startPoint.y + dy;
            x = obj.startPoint.x + dx;
        end   
        
        function [x, y] = diff(obj, s)
           x = cos(obj.phi);
           y = sin(obj.phi);
        end
        
        function diffObj = diffAnalytical(obj)
           [x1,y1] = obj.diff(0);
           [x2,y2] = obj.diff(obj.length);
           diffObj = LinearSpline([x1,x2],[y1,y2]);
        end
    end
    
    methods( Access = protected)
         function len = calculateLength(obj)
            len = sqrt((obj.startPoint.x - obj.endPoint.x)^2+(obj.startPoint.y - obj.endPoint.y)^2);
         end
    end
    
    
end
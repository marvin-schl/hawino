classdef LinearSpline < Spline

    properties
       startPoint
       endPoint 
    end
    
    properties (Access = private)
        
    end   

    methods 
        function obj = LinearSpline(x,y)
            obj.startPoint      = struct("x", x(1), "y", y(1));
            obj.endPoint        = struct("x", x(2), "y", y(2));
            phi             = atan2(obj.endPoint.y-obj.startPoint.y, obj.endPoint.x-obj.startPoint.x);
            obj.startPoint.phi = phi;
            obj.endPoint.phi = phi;
            obj.length          = obj.calculateLength();
        end
        
        function [x,y] = getPoint(obj, s)
         
            dx = cos(obj.startPoint.phi).*s;
            dy = sin(obj.startPoint.phi).*s;
            
            y = obj.startPoint.y + dy;
            x = obj.startPoint.x + dx;
        end   
        
        function [x, y] = diff(obj, s, order)
          if (~exist("order","var"))
               order = 1;
           end
           switch order
               case 1
                   x = cos(obj.startPoint.phi);
                   y = sin(obj.startPoint.phi);
             otherwise   
                   x = 0;
                   y = 0;           
           end
        end

    end
    
    methods( Access = protected)
         function len = calculateLength(obj)
            len = sqrt((obj.startPoint.x - obj.endPoint.x)^2+(obj.startPoint.y - obj.endPoint.y)^2);
         end
    end
    
    
end
classdef LinearSpline
    properties
        
    end

    properties (Access =private)
        x
        y 
        m
    end
    
    
    methods 
        function obj = LinearSpline(x,y)
            obj.x = x
            obj.y = y
            if x(1) ~= x(2)
                obj.m = diff(y)/diff(x);
            end   
        end
        
        function [x,y] = getPoint(obj, s)
            if  x(1) == x(2)
              dy = s;
              dx = 0;
            else
              dx = cos(atan(obj.m))*s;
              dy = sqrt(s^2-dx^2);
            end
            y = obj.y[1] + sign(m)*dy
            x = obj.x[1] + sign(m)*dx
        end   
        
        function len = getLength(obj)
            len = sqrt(diff(x)^2+diff(y)^2)
        end
    end
    
    methods (Access = private)
        
        
    end
end
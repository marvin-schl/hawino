classdef Spline <  matlab.mixin.Heterogeneous
    properties (Abstract)
       startPoint
       endPoint 
    end

    methods (Abstract)
       getPoint(obj, s)   
       getLength(obj)
       %diff(obj, s, order)
    end
    
    methods
        function obj = Spline()
        end
        
        
       function [x_t,y_t] = diff(obj, s, order)
            if (~exist("order","var"))
                order = 1;
            end
           
            x_t = derivest(@(x)func_x(x,obj), s, 'Style','forward', 'DerivativeOrder', order);
            y_t = derivest(@(y)func_y(y,obj), s, 'Style', 'forward', 'DerivativeOrder', order);

            function x = func_x(s,obj)
                [x,~] = obj.getPoint(s);
            end

            function y = func_y(s,obj)
                [~,y] = obj.getPoint(s);
            end   
       end
    end
end


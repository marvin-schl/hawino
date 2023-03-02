classdef Spline <  matlab.mixin.Heterogeneous
    properties (Abstract)
       startPoint
       endPoint 
    end

    properties
      length
    end
    
   methods (Static, Sealed, Access = protected)
      function default_object = getDefaultScalarElement
         default_object = LinearSpline([0,0],[0,0]);
      end
   end
    
    methods (Abstract)
       getPoint(obj, s)   
    end
    
    methods ( Access=protected, Abstract)
       calculateLength
    end
    
    methods
        function obj = Spline()
        end
        
        function length = getLength(obj) 
            length = obj.length;
        end
        
       function [x_t,y_t] = diff(obj, s, order)
            if (~exist("order","var"))
                order = 1;
            end
           
            x_t = derivest(@(x)func_x(x,obj), s, 'Style','forward','MethodOrder', 4, 'DerivativeOrder', order);
            y_t = derivest(@(y)func_y(y,obj), s, 'Style','forward','MethodOrder', 4, 'DerivativeOrder', order);

            function x = func_x(s,obj)
                [x,~] = obj.getPoint(s);
            end

            function y = func_y(s,obj)
                [~,y] = obj.getPoint(s);
            end   
       end
    end
end


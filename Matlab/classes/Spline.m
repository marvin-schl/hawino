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
       diff
    end
    

    methods ( Access=protected,Abstract)
       calculateLength
    end
            
    
    methods
        function obj = Spline()
        end
        
        function length = getLength(obj) 
            length = obj.length;
        end
        
    end
    
end


classdef Path < Spline
    properties
        startPoint
        endPoint
        transitions
        subsplines
    end
    
    methods 
        function obj = Path(x,y,r)
           
           nmbSubSplines = 2*length(x)-3;
           subsplines   = Spline.empty(nmbSubSplines,0);
           obj.transitions  = zeros(length(obj.subsplines)-1,1);
           
           %generate bezier curves
           for i = 2:2:nmbSubSplines-1
               subsplines(i) = QuadraticBezierCurve(x(i/2:i/2+2),y(i/2:i/2+2),r);
           end
           
           %generate first linear
           subsplines(1) = LinearSpline(...
                            [x(1),subsplines(2).startPoint.x],...
                            [y(1),subsplines(2).startPoint.y]);
                        
           %generate last linear
           subsplines(nmbSubSplines) = LinearSpline(...
                        [subsplines(nmbSubSplines-1).endPoint.x, x(length(x))],...
                        [subsplines(nmbSubSplines-1).endPoint.y, y(length(y))]);

           %generate linears in between
           for i = 3:2:nmbSubSplines-2
                x = [subsplines(i-1).endPoint.x,subsplines(i+1).startPoint.x];
                y = [subsplines(i-1).endPoint.y,subsplines(i+1).startPoint.y];
                subsplines(i) = LinearSpline(x,y);
           end
           
           obj.subsplines = subsplines;
           obj.length = obj.calculateLength();
           obj.transitions = obj.calculateTransitions();
           obj.startPoint = struct("x", x(1), "y", y(1));
           obj.endPoint =  struct("x", x(length(x)), "y", y(length(y)));      
        end
        
        function [x,y] = getPoint(obj, s)
            [idx, s_offset] = obj.getSubsplineToPoint(s);
            x = zeros(length(s),1);
            y = zeros(length(s),1);
            for i = 1:length(idx)
                [x(i),y(i)] = obj.subsplines(idx(i)).getPoint(s_offset(i));
            end
        end
        
        function [x,y] = diff(obj, s, order)
           if (~exist("order","var"))
               order = 1;
           end
            
            x = zeros(length(s),1);
            y = zeros(length(s),1);
            
            [idx, s_offset] = obj.getSubsplineToPoint(s);
            for i = 1:length(idx)                 
                [x(i),y(i)] = obj.subsplines(idx(i)).diff(s_offset(i), order);
            end
            
        end
    end
    
    methods (Access = private)
        function [idx, s_offset] = getSubsplineToPoint(obj, s)
%           splineIdx = zeros(length(s),1);
%             for i = 1:length(s)
%                 idx = find((obj.transitions < s(i)) == 1,1,"last");
%                 if isempty(idx)
%                     idx = length(obj.transitions);
%                 end
%                 splineIdx(i,1) = idx-1;
%             end
            idx = zeros(length(s),1);
            s_offset = zeros(length(s),1);
            for i=1:length(s)
                idx(i) = 1;
                s_offset(i) = s(i);
                while s_offset(i) - obj.subsplines(idx(i)).length() > 0 && idx(i) < length(obj.subsplines)
                    s_offset(i) = s_offset(i) - obj.subsplines(idx(i)).length;
                    idx(i) = idx(i) + 1;
                end
                
                
            end
        end
        
        function t = calculateTransitions(obj)    
            t = zeros(length(obj.subsplines)-1,1);
            for i = 1:length(obj.subsplines)
                t(i+1,1) = t(i,1) + obj.subsplines(i).getLength();
            end
        end
        
        
    end
    
    methods (Access = protected)
        function len = calculateLength(obj)
            len = 0;
            for i = 1:length(obj.subsplines)
                len = len + obj.subsplines(i).getLength();
            end
        end
    end
    
end

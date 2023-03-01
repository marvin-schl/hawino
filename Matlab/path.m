classdef Path < Spline
    properties
        startPoint
        endPoint
        transitions
    end
    
    properties (Access=private)
        subsplines
        
    end
    
    methods 
        function obj = Path(x,y)
           obj.subsplines = Spline.empty(length(x)-1,0);
           for i = 1:length(x)-1
                obj.subsplines(i) = LinearSpline(x(i:i+1),y(i:i+1));
           end
           obj = obj.calculateTransitions();
        end
        
        function [x,y] = getPoint(obj, s)
            idx = obj.getSubsplineToPoint(s);
            x = zeros(length(s),1);
            y = zeros(length(s),1);
            for i = 1:length(idx)
                [x(i),y(i)] = obj.subsplines(idx(i)).getPoint(s(i)-obj.transitions(idx(i)));
            end
        end
        
        function len = getLength(obj)
            len = 0;
            for i = 1:length(obj.subsplines)
                len = len + obj.subsplines(i).getLength();
            end
        end
    end
    
    methods (Access = private)
        function splineIdx = getSubsplineToPoint(obj, s)
            splineIdx = zeros(length(s),1);
            for i = 1:length(s)
                idx = find((obj.transitions <= s(i)) == 0,1);
                if isempty(idx)
                    idx = length(obj.transitions);
                end
                splineIdx(i,1) = idx-1;
            end
            
        end
        
        function obj = calculateTransitions(obj)    
            t = zeros(length(obj.subsplines)-1);
            for i = 1:length(obj.subsplines)
                t(i+1) = t(i) + obj.subsplines(i).getLength();
            end 
            obj.transitions = t;
        end
    end
        
end
% function [x,y] = path(s, wpx, wpy, splineType)
%     %calculate switching points in s   
%     if any(s  < 0)
%         ex = MException('Path:NotDefined',"Path only defined for positive s.");
%         throw(ex)
%     end
%     
%     s_switch = [0, cumsum(sqrt(diff(wpx).^2+diff(wpy).^2))];
%     splineIdx = zeros(length(s),1);
%     m         = diff(wpy)./diff(wpx)
%     x         = zeros(length(s),1);
%     y         = zeros(length(s),1);
%     
%     for i = 1:length(s)
%         idx = find((s_switch <= s(i)) == 0,1);
%         if length(idx) == 0
%             idx = length(s_switch);
%         end
%         splineIdx(i,1) = idx-1;
%     end
%     for i = 1:length(splineIdx)
%         idx = splineIdx(i,1);
%         switch abs(m(idx))
%             case 0
%               
%               %%linear with valid analytical description
%               dx = cos(atan(m(idx)))*(s(i)-s_switch(idx));
%               dy = sqrt((s(i)-s_switch(idx))^2-dx^2);
%             case 1
%               %%linear with dx=0, without analytical description
%               dy = (s(i)-s_switch(idx));
%               dx = 0;
%             case 2
%                 throw(MException("Path:BezierNotImplemented", "Not implemented Bezier yet."));
%         end 
%         x(i,1) = wpx(idx) + sign(wpx(idx+1)-wpx(idx))*dx;
%         y(i,1) = wpy(idx) + sign(wpy(idx+1)-wpy(idx))*dy;
%     end
% end


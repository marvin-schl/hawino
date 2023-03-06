function [wpx, coeffs] = getSpline(wpx,wpy,order)
len = length(wpx);
coeffs = zeros(order+1,len-1);
%calculate piecewise polynomials coeffiecients
for i = 1:len-1
    A = [1 wpx(i);
         1 wpx(i+1)];
    if i == 1 
        a2 = (wpy(2)-wpy(1))/(wpx(2)-wpx(1));
        a1 = wpy(1) - a2*wpx(1);

       coeffs(:,i) = [a1;a2];
    else
        y = [wpy(i);
            wpy(i+1)];
        coeffs(:,i) = A^-1*y;
    end
end
end


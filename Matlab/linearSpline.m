function coeffs = linearSpline(wpx, wpy, coeffs)
%coeffs = zeros(size(coeffs));
for i = 1 : length(wpx) - 1
    A = [1 wpx(i);
         1 wpx(i+1)];
    if i == 1 
        a2 = (wpy(2) - wpy(1)) / (wpx(2) - wpx(1));
        a1 = wpy(1) - a2 * wpx(1);

       coeffs(1:2, i) = [a1; a2];
    else
        y = [wpy(i);
            wpy(i+1)];
        coeffs(1:2, i) = A^-1 * y;
      
    end   
end
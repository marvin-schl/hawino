function coeffs = linearSpline(wpx, wpy, coeffs)
for i = 1 : length(wpx) - 1
    if wpx(i) == wpx(i+1)
        %straight line up, no analytical description possible
        coeffs(1:2,i) = zeros(2,1);
    else
         %linear function
         A = [1 wpx(i);
         1 wpx(i+1)];
        
        y = [wpy(i);
            wpy(i+1)];
        coeffs(1:2, i) = A^-1 * y;
      
    end   
end
function coeffs = cubicalSpline(wpx, wpy, coeffs)
for i = 2 : 2 : length(wpx) - 1
    A = [1     wpx(i)                   wpx(i)^2      wpx(i)^3;
         1     wpx(i+1)                 wpx(i+1)^2    wpx(i+1)^3;
         0     1          2*wpx(i)      3*wpx(i)^2;
         0     1          2*wpx(i+1)    3*wpx(i+1)^2                   ];
    if i == 1 
        a4 = 0;
        a3 = 0;
        a2 = (wpy(2)-wpy(1))/(wpx(2)-wpx(1));
        a1 = wpy(1) - a2*wpx(1);

       coeffs(1:4, i) = [a1;a2;a3;a4];
    else
        y = [wpy(i);
            wpy(i+1);
            coeffs(2,i-1)+2*coeffs(3,i-1)*wpx(i)+3*coeffs(4,i-1)*wpx(i)^2;
            coeffs(2,i+1)+2*coeffs(3,i+1)*wpx(i+1)+3*coeffs(4,i+1)*wpx(i+1)^2];
        
        coeffs(1:4, i) = A^-1*y;
      
    end
end
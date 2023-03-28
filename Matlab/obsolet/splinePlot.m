function splinePlot(wpx, g, coeffs, dx)
x = [min(wpx):dx:max(wpx)];
for i = 1 : length(wpx) - 1
    if wpx(i) <= wpx(i+1)
        x = [wpx(i):0.01:wpx(i+1)];
    else
        x = [wpx(i+1):0.01:wpx(i)];
    end
    
   plot(x, g(x,coeffs(:,i)))
end
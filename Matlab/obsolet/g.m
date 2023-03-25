function t = g(coeff,x,n,v)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    nmbSplines = length(coeff);
    t = 0;
    for i = 1:nmbSplines
       tk = abs((x(i)-x(i+1)))/n;
       for k = 1:n
        vk  = v(i*n+k);
        tn  = 1/vk*sqrt((coeff(1,i)+tk*vk*sin(atan(coeff(2,i))))^2+(tk*vk*cos(atan(coeff(2,i))))^2);
        t   = t + tn;
       end
    end
end


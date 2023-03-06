function [P, len] = getBezierCurve(x, y, dx)

bezierPoints = [x' y'];
n = length(x);
n1 = n - 1;

for i = 0 : 1 : n1
    sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
end

l = [];
UB = [];

for u = 0.2
    for d = 1 : n
        UB(d) = sigma(d)*((1-u)^(n-d))*(u^(d-1));
    end
    
    l = cat(1,l,UB);                                       
end

P = l * bezierPoints;

x = P(:, 1);
y = P(:, 2);

len = sum(sqrt(diff(x).^2 + diff(y).^2));



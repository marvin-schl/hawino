%Hello! this will plot Bezier curve for n control points 
%This is a replacement of the program 'Parametic Cubic Bezier Curve'
%submitted before ...Bezier for any number of points ...enjoy 
clear all, clc, close all

wpx = [0, 1, 1, 2, 5, 6];
wpy = [0, 0, 1, 0, 5, 2];

bezierPoints = [wpx' wpy'];
n = length(wpx);
n1 = n - 1;

for i = 0 : 1 : n1
    sigma(i+1) = factorial(n1) / (factorial(i)*factorial(n1-i)); 
end

l = [];
UB = [];

for u = 0 : 0.002 : 1
    for d = 1 : n
        UB(d) = sigma(d)*((1-u)^(n-d))*(u^(d-1));
    end
    
    l = cat(1,l,UB);                                       
end

P = l * bezierPoints;
line(P(:,1),P(:,2))
line(bezierPoints(:,1), bezierPoints(:,2))

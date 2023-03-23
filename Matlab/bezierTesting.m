% better plots
clear all
% This script changes all interpreters from tex to latex. 
list_factory = fieldnames(get(groot,'factory'));
index_interpreter = find(contains(list_factory,'Interpreter'));
for i = 1:length(index_interpreter)
    default_name = strrep(list_factory{index_interpreter(i)},'factory','default');
    set(groot, default_name,'latex');
end
%%

clear all, clc, close all

wpx = [0, 1, 1];
wpy = [0.5, .5, 2];
r = 0.5;
ds = 1e-3;

myCurve = BezierCurve(wpx, wpy, r, ds);
myCurve.length

s = [0:ds:myCurve.length];

figure()
hold on
grid minor
plot(wpx, wpy, '*', 'color', 'blue', 'MarkerSize', 16)

[x, y] = myCurve.getPoint(s);
plot(x,y)

plot(myCurve.startPoint.x, myCurve.startPoint.y, '+', 'color', 'red', 'MarkerSize', 16)
plot(myCurve.endPoint.x, myCurve.endPoint.y, '+', 'color', 'red', 'MarkerSize', 16)
line([wpx(1); myCurve.startPoint.x], [wpy(1); myCurve.startPoint.y], 'color', 'black')
line([wpx(3); myCurve.endPoint.x], [wpy(3); myCurve.endPoint.y], 'color', 'black')

xval = wpx(2) - r : ds : wpx(2) + r;
plot(xval, sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')
plot(xval, -sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')

xlabel("$x$"), ylabel("$y$")

xlim([0, 2]), ylim([0, 2])


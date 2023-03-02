clear all, clc, close all

wpx = [0, 5, 10];
wpy = [0, 1, 4];
r = .5;
dx = 1e-3;

myCurve = BezierCurve(wpx, wpy, r, dx);

figure()
hold on
grid minor
plot(wpx, wpy, '*', 'color', 'blue')
plot(myCurve.curvePoints.x, myCurve.curvePoints.y, 'color', 'green');
plot(myCurve.startPoint.x, myCurve.startPoint.y, '+')
plot(myCurve.endPoint.x, myCurve.endPoint.y, '+')
line([wpx(1); myCurve.startPoint.x], [wpy(1); myCurve.startPoint.y], 'color', 'black')
line([wpx(3); myCurve.endPoint.x], [wpy(3); myCurve.endPoint.y], 'color', 'black')

xval = wpx(2) - r : dx : wpx(2) + r;
plot(xval, sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')
plot(xval, -sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')


clear all, clc, close all

wpx = [0, 5, 10];
wpy = [0, 0, 0];
r = 0.5;
ds = 1e-3;

myCurve = BezierCurve(wpx, wpy, r, ds);

figure()
hold on
grid minor
plot(wpx, wpy, '*', 'color', 'blue')
plot(myCurve.curvePoints.x, myCurve.curvePoints.y, 'color', 'black');
plot(myCurve.startPoint.x, myCurve.startPoint.y, '+', 'color', 'red')
plot(myCurve.endPoint.x, myCurve.endPoint.y, '+', 'color', 'red')
line([wpx(1); myCurve.startPoint.x], [wpy(1); myCurve.startPoint.y], 'color', 'black')
line([wpx(3); myCurve.endPoint.x], [wpy(3); myCurve.endPoint.y], 'color', 'black')

xval = wpx(2) - r : ds : wpx(2) + r;
plot(xval, sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')
plot(xval, -sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')


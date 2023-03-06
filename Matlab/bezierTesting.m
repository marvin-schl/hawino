clear all, clc, close all

wpx = [0, 2, 2];
wpy = [0, 0, 2];
r = 1;
ds = 1e-3;

myCurve = BezierCurve(wpx, wpy, r, ds);
myCurve.length

s = [0:ds:myCurve.length]

figure()
hold on
grid minor
plot(wpx, wpy, '*', 'color', 'blue')

[x, y] = myCurve.getPoint(s);
plot(x,y)

plot(myCurve.endPoint.x, myCurve.endPoint.y, '+', 'color', 'red')
line([wpx(1); myCurve.startPoint.x], [wpy(1); myCurve.startPoint.y], 'color', 'black')
line([wpx(3); myCurve.endPoint.x], [wpy(3); myCurve.endPoint.y], 'color', 'black')

xval = wpx(2) - r : ds : wpx(2) + r;
plot(xval, sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')
plot(xval, -sqrt(r^2 - (xval - wpx(2)).^2) + wpy(2), ':', 'color', 'black')


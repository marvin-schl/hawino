clear all, clc, close all
wpx = [0, 5, 10];
wpy = [0, 1, 4];

myCurve = BezierCurve(wpx, wpy, 3, 0.01);

plot(wpx, wpy, '*', 'color', 'blue')
hold
plot(myCurve.curvePoints.x, myCurve.curvePoints.y, 'color', 'green');


plot(point(1), point(2), 'o', 'color', 'Red')
plot(myCurve.startPoint.x, myCurve.startPoint.y, '+')
plot(myCurve.endPoint.x, myCurve.endPoint.y, '+')
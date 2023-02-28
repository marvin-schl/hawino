close all; clear, clc

% Waypoints
wpx = [-2, 1, 2, 2.2, 4];
wpy = [0, 5, 5, 10, 10];


% Initializations and constants
wpx2 = zeros(1, 2 + (length(wpx) - 2) * 2);
wpy2 = zeros(1, length(wpx2));
R = .4;
dx = 0.01;
coeffs = zeros(6, length(wpx) - 1);
zpx = zeros(2, length(wpx) - 1);
zpy = zeros(2, length(wpy) - 1);

% Step 1: Determine linear connections between WPs
coeffs = linearSpline(wpx, wpy, coeffs);

% Step 2: Determine ZPs (points where linear connections cross circles)
for i = 2 : length(wpx) - 1
    % ZP 1:    
    zpx11 = wpx(i) - R * cos(atan(coeffs(2, i-1)));
    zpx12 = wpx(i) + R * cos(atan(coeffs(2, i-1)));
    
    % decide which of the 2 solutions is the relevant one
    if wpx(i-1) < wpx(i)
        zpx1 = zpx11;
    else
        zpx1 = zpx12;
    end

    zpy1 = coeffs(1, i-1) + coeffs(2, i-1)*zpx1;

    % ZP 2:
    zpx21 = wpx(i) - R * cos(atan(coeffs(2, i)));
    zpx22 = wpx(i) + R * cos(atan(coeffs(2, i)));

    % decide which of the 2 solutions is the relevant one
    if wpx(i) < wpx(i+1)
        zpx2 = zpx22;
    else
        zpx2 = zpx21;
    end

    zpy2 = coeffs(1, i) + coeffs(2, i)*zpx2;

    zpx(1, i) = zpx1;
    zpx(2, i) = zpx2;
    zpy(1, i) = zpy1;
    zpy(2, i) = zpy2;
end


% Step 3: Create new waypoints
wpx2(1) = wpx(1);
wpx2(length(wpx2)) = wpx(length(wpx));
wpy2(1) = wpy(1);
wpy2(length(wpy2)) = wpy(length(wpy));

for i = 2 : length(wpx2) - 1
    if ~mod(i, 2)
        wpx2(i) = zpx(1, ceil(i/2) + 1);
        wpy2(i) = zpy(1, ceil(i/2) + 1);
    else
        wpx2(i) = zpx(2, ceil(i/2));
        wpy2(i) = zpy(2, ceil(i/2));
    end
end


% Step 4: Create linear subsplines
coeffs = linearSpline(wpx2, wpy2, coeffs);
coeffs = biquadraticalSpline(wpx2, wpy2, coeffs);







g = @(x, coeffs) ( coeffs(1) + coeffs(2)*x + coeffs(3)*x.^2 + coeffs(4)*x.^3 + coeffs(5)*x.^4 + coeffs(6)*x.^5);

plot(wpx,wpy,"*")
xlim([-1, 11]), ylim([-1, 11])
grid on
hold on;
splinePlot(wpx2, g, coeffs, dx)

% plot circles and crossing points
for i = 2 : length(wpx) - 1
    plot(wpx(i), wpy(i), 'o')

    xval = wpx(i)-R : dx : wpx(i)+R;

    plot(xval, sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
    plot(xval, -sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))

    % plot crossing points
    for j = 1:2
       plot(zpx(j,i), zpy(j,i), 'x');
    end
end
   




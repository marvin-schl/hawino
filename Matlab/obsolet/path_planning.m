close all; clear, clc
% === INPUTS ===
wpx = [0, 2, 2, 0, 0, 1, 1.5, 0.5];
wpy = [0, 0, 2, 2, 0, 0, 1,   1];
dx = 0.01;
R = 0.4;

% wpx = p(:, 1)';
% wpy = p(:, 2)';

% === INITIALIZATIONS ===
zpx = zeros(1, 2 * (length(wpx) - 2));
zpy = zeros(1, 2 * (length(wpy) - 2));

% Step 1: Determine ZPs (points where linear connections cross circles)
j = 1;
for i = 2 : length(wpx) - 1
    % ZP 1:
    % - angle of incidence of former linear part
    phi1 = atan2((wpy(i) - wpy(i-1)),(wpx(i) - wpx(i-1)));
    
    % - x-coordinates where former linear part intersects with circle
    zpx11 = wpx(i) - R * cos(phi1);
    zpx12 = wpx(i) + R * cos(phi1);
    % - y-coordinates where former linear part intersects with circle
    zpy11 = wpy(i) - R * sin(phi1);
    zpy12 = wpy(i) + R * sin(phi1);

    % - decide which of the 2 solutions the relevant one 
    % (left or right intersection)
    if wpx(i-1) < wpx(i)
        zpx1 = min(zpx11, zpx12);
    else
        zpx1 = max(zpx11, zpx12);
    end

    if wpy(i-1) < wpy(i)
        zpy1 = min(zpy11, zpy12);
    else
        zpy1 = max(zpy11, zpy12);
    end

    % ZP 2:
    % - angle of incidence of following linear part
    phi2 = atan2((wpy(i+1) - wpy(i)),(wpx(i+1) - wpx(i)));

    % - x-coordinates where following linear part intersects with circle
    zpx21 = wpx(i) - R * cos(phi2);
    zpx22 = wpx(i) + R * cos(phi2);
    % - y-coordinates where former linear part intersects with circle
    zpy21 = wpy(i) - R * sin(phi2);
    zpy22 = wpy(i) + R * sin(phi2);

    % - decide which of the 2 solutions the relevant one 
    % (left or right intersection)
    if wpx(i+1) < wpx(i)
        zpx2 = min(zpx21, zpx22);
    else
        zpx2 = max(zpx21, zpx22);
    end

    if wpy(i+1) < wpy(i)
        zpy2 = min(zpy21, zpy22);
    else
        zpy2 = max(zpy21, zpy22);
    end

    zpx(j) = zpx1;
    zpx(j+1) = zpx2;
    zpy(j) = zpy1;
    zpy(j+1) = zpy2;
    
    j = j + 2;
end

% Step 2: Create extended waypoints (given waypoints and bezier points)
extWPx = zeros(1, 3 * (length(wpx) - 2) + 2);
extWPy = zeros(1, 3 * (length(wpy) - 2) + 2);

% 2.1 - first an last extended waypoint
extWPx(1) = wpx(1);
extWPy(1) = wpy(1);
extWPx(length(extWPx)) = wpx(length(wpx));
extWPy(length(extWPy)) = wpy(length(wpy));

% 2.2 - middle extended way points:
% 2.2.1 very third extended waypoint is an originally given waypoint
for i = 3 : 3: length(extWPx) - 1
    extWPx(i) = wpx(i/3 + 1);
    extWPy(i) = wpy(i/3 + 1);
end

% 2.2.2 the other middle extended waypoints are the intersections with circles
j = 1;
for i = 2 : length(extWPx) - 1
    % skip every third extWP since it is already included by former loop
    if mod(i, 3)
        extWPx(i) = zpx(j);
        extWPy(i) = zpy(j);
        j = j + 1;
    end
end

% Step 3 - Calculate Bezier curves
P = [];
lenP = [];
j = 1;
for i = 2 : 3 : length(extWPx) - 2
    x = [extWPx(i), extWPx(i+1), extWPx(i+2)];
    y = [extWPy(i), extWPy(i+1), extWPy(i+2)];
    [P(:,:,j), lenP(j)] = getBezierCurve(x, y, dx);
    j = j+1;
end


% === PLOTS ===
figure()
hold on

% Plot Waypoints
plot(wpx,wpy,"*")

% Plot linear splines
for i = 1 : 3 : length(extWPx) - 1
    line([extWPx(i); extWPx(i+1)], [extWPy(i); extWPy(i+1)])
end

% Plot circles and crossing points
for i = 2 : length(wpx) - 1
    xval = wpx(i)-R : dx : wpx(i)+R;
    % Circles
    plot(xval, sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
    plot(xval, -sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
    % Crossing points
    plot(zpx(i-1), zpy(i-1), 'x');
end

% Plot Bezier curves
for i = 1 : length(wpx) - 2
    plot(P(:, 1, i), P(:, 2, i), 'o')
    display(lenP(i))
end



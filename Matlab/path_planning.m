close all; clear, clc
% Inputs
wpx = [0, 1, 1, 2, 4, 5];
wpy = [0, 1, 2, 2, 3, 1];
dx = 0.01;
R = 0.5;

% Initializations
zpx = zeros(2, length(wpx) - 1);
zpy = zeros(2, length(wpy) - 1);


% Step 2: Determine ZPs (points where linear connections cross circles)
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

    zpx(1, i) = zpx1;
    zpx(2, i) = zpx2;
    zpy(1, i) = zpy1;
    zpy(2, i) = zpy2;
end


% Plots
figure()
plot(wpx,wpy,"*")
hold on

% plot circles and crossing points
for i = 2 : length(wpx) - 1
    xval = wpx(i)-R : dx : wpx(i)+R;

    plot(xval, sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
    plot(xval, -sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))

    % plot crossing points
    for j = 1:2
       plot(zpx(j,i), zpy(j,i), 'x');
    end
end



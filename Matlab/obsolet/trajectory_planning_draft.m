close all; clear, clc


wpx = [0, 1, 1, 4, 5, 5, 6];
wpy = [0, 0, 1,    1, 2, 0, 0];

% Initializations and constants
wpx2 = zeros(1, 2 + (length(wpx) - 2) * 2);
wpy2 = zeros(1, length(wpx2));
R = 0.3;
dx = 0.01;
coeffs = zeros(6, length(wpx) - 1);
zpx = zeros(2, length(wpx) - 1);
zpy = zeros(2, length(wpy) - 1);

% Step 1: Determine linear connections between WPs
coeffs = linearSpline(wpx, wpy, coeffs);

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


% Step 4: Create linear splines
coeffs = linearSpline(wpx2, wpy2, coeffs);
plot(wpx2,wpy2)

% % Bezier ---
% 
% allWpx = zeros(1, 2 * length(wpx) + 3);
% allWpy = zeros(1, 2 * length(wpy) + 3);
% 
% allWpx(1) = wpx(1);
% allWpy(1) = wpy(1);
% allWpx(length(allWpx)) = wpx(length(wpx));
% allWpy(length(allWpy)) = wpy(length(wpy));
% 
% j = 2;
% 
% for i = 2 : length(allWpx) - 1
%     if ~mod(i, 3)
%         allWpx(i) = wpx(i/3 + 1);
%         allWpy(i) = wpy(i/3 + 1);
%     else
%         allWpx(i) = wpx2(j);
%         allWpy(i) = wpy2(j);
%         j = j + 1;
%     end
% end
% 
% 
% n = 3;
% n1 = n - 1;
% 
% 
% for i = 2 : 3 : length(allWpx) - 2
%     bezierPoints = [allWpx(i) allWpy(i); allWpx(i+1) allWpy(i+1); allWpx(i+2) allWpy(i+2)];
%     
%     for j = 0 : 1 : n1
%         sigma(j+1) = factorial(n1) / (factorial(j)*factorial(n1-j)); 
%     end
%     
%     l = [];
%     UB = [];
%     
%     for u = 0 : dx : 1
%         for d = 1 : n
%             UB(d) = sigma(d)*((1-u)^(n-d))*(u^(d-1));
%         end
%         
%         l = cat(1,l,UB);                                       
%     end
% 
%     P = l * bezierPoints;
%     line(P(:,1),P(:,2))
%     hold on
%     %line(bezierPoints(:,1), bezierPoints(:,2))
% end
% 
% g = @(x, coeffs) ( coeffs(1) + coeffs(2)*x + coeffs(3)*x.^2 + coeffs(4)*x.^3 + coeffs(5)*x.^4 + coeffs(6)*x.^5);
% 
% plot(wpx,wpy,"*")
% %xlim([-1, 11]), ylim([-1, 11])
% grid on
% hold on;
% splinePlot(wpx2, g, coeffs, dx)
% 
% % plot circles and crossing points
% for i = 2 : length(wpx) - 1
%     %plot(wpx(i), wpy(i), 'o')
% 
%     xval = wpx(i)-R : dx : wpx(i)+R;
% 
%     plot(xval, sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
%     plot(xval, -sqrt(R^2 - (xval - wpx(i)).^2) + wpy(i))
% 
%     % plot crossing points
%     for j = 1:2
%        plot(zpx(j,i), zpy(j,i), 'x');
%     end
% end
% 
% 
% 
% 









% Optimization ---
   

%wpx = [0, 1, 2];
%wpy = [0, 2, 1];
%[wpx, coeffs] = getSpline(wpx, wpy,1);

%plot polynomials
%plot(wpx,wpx)
%hold on;
% for i = 1:length(wpx)-1
%     if wpx(i) <= wpx(i+1)
%         x_vals = [wpx(i):0.01:wpx(i+1)];
%     else
%         x_vals = [wpx(i+1):0.01:wpx(i)];
%     end
%    y_vals = f(x_vals,coeffs(:,i));
%    plot(x_vals, y_vals)
% end
% %select spline
% i = 2;
% a = coeffs(:,i);
% xstart = wpx(i);
% xend = wpx(i+1);
% %create optim problem
% problem = optimproblem('ObjectiveSense','minimize');
% nmbPoints = 50;
% x = optimvar("x", nmbPoints, 1);
% t = optimvar("t", nmbPoints, 1);
% 
% t0 = [1:1/(nmbPoints-1):2].^2;
% x0 = t0;
% x0 = struct("x",x0,"t",t0);
% problem.Objective = t(nmbPoints);
% 
% %start endwert in x
% problem.Constraints.x0 =   x(1)         == xstart;
% problem.Constraints.xend = x(nmbPoints) == xend;
% 
% %startwert in v
% problem.Constraints.v0 =   diff(x(1:2))./diff(t(1:2)) == 0;
% 
% %start bei t=0
% problem.Constraints.t0 = t(1) == 0;
% 
% %monoton in x und t
% problem.Constraints.xmono = diff(x) >= 0;
% problem.Constraints.tmono = diff(t) >= 0;
% 
% %max beschl.
% vmax = 1;
% problem.Constraints.v1 = sqrt((diff(x,1)./diff(t,1)).^2+ (diff(S(x,a),1)./diff(t,1)).^2) <=vmax;
% problem.Constraints.v2 = sqrt((diff(x,1)./diff(t,1)).^2+ (diff(S(x,a),1)./diff(t,1)).^2) >= -vmax;
% 
% 
% %max beschl.
% amax = 1;
% problem.Constraints.a1 = sqrt((diff(x,2)./diff(t,2)).^2+ (diff(S(x,a),2)./diff(t,2)).^2) <= amax;
% problem.Constraints.a2 = sqrt((diff(x,2)./diff(t,2)).^2+ (diff(S(x,a),2)./diff(t,2)).^2) >= -amax;
% 
% 
% sol = solve(problem, x0);
% 
% %plot(sol.t, sol.x)
% %plot(sol.x, S(sol.x,a))

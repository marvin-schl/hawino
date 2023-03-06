%wpx = [1,3,4.8,5,4.8,3,1.2,1,0.99];
%wpy = [1,1,1.2,1.5,1.8,2,1.8,1.5,1];

wpy = [0, 0, 1, 5];
wpx = [0, 3, 5, 7];

%wpx = [0, 1, 2];
%wpy = [0, 2, 1];
[wpx, coeffs] = getSpline(wpx, wpy,1);

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

%select spline
i = 2;
a = coeffs(:,i);
xstart = wpx(i);
xend = wpx(i+1);
%create optim problem
problem = optimproblem('ObjectiveSense','minimize');
nmbPoints = 50;
x = optimvar("x", nmbPoints, 1);
t = optimvar("t", nmbPoints, 1);

t0 = [1:1/(nmbPoints-1):2].^2;
x0 = t0;
x0 = struct("x",x0,"t",t0);
problem.Objective = t(nmbPoints);

%start endwert in x
problem.Constraints.x0 =   x(1)         == xstart;
problem.Constraints.xend = x(nmbPoints) == xend;

%startwert in v
problem.Constraints.v0 =   diff(x(1:2))./diff(t(1:2)) == 0;

%start bei t=0
problem.Constraints.t0 = t(1) == 0;

%monoton in x und t
problem.Constraints.xmono = diff(x) >= 0;
problem.Constraints.tmono = diff(t) >= 0;

%max beschl.
vmax = 1;
problem.Constraints.v1 = sqrt((diff(x,1)./diff(t,1)).^2+ (diff(S(x,a),1)./diff(t,1)).^2) <=vmax;
problem.Constraints.v2 = sqrt((diff(x,1)./diff(t,1)).^2+ (diff(S(x,a),1)./diff(t,1)).^2) >= -vmax;


%max beschl.
amax = 1;
problem.Constraints.a1 = sqrt((diff(x,2)./diff(t,2)).^2+ (diff(S(x,a),2)./diff(t,2)).^2) <= amax;
problem.Constraints.a2 = sqrt((diff(x,2)./diff(t,2)).^2+ (diff(S(x,a),2)./diff(t,2)).^2) >= -amax;


sol = solve(problem, x0);

%plot(sol.t, sol.x)
%plot(sol.x, S(sol.x,a))

% ===== VAR INPUT =========================================================
% Reference values
xR;         % Reference position, x-coordinate in global frame
yR;         % Reference poisiton, y-cooridnate in global frame
thetaR;     % Reference orientiation in global frame
vR;         % Reference linear velocity (tangential to path)          
vThetaR;    % Reference angular velocity

% Actual values
x;          % Actual position, x-coordinate in global frame
y;          % Actual position, y-coordinate in global frame
theta;      % Actual orientation in global frame
v;          % Actual linear velocity (tangential to path)
vTheta;     % Actual angular velocity

% Control parameters
k1;         % Control parameter, chose k1 > k3
k3;         % Control parameter, chose k3 > 0
% ===== END VAR ===========================================================

% ===== VAR OUTPUT ========================================================
vX;         % x-component of linear velocity (to low-level controller)
vY;         % y-component of linear velocity (to low-level controller)
vTheta;     % Angular velocity (to low-level controller)
% =========================================================================

% ===== VAR ===============================================================
k2;         % Control parameter (fixed)
xE;         % Robot pose error in mobile frame (x-component)
yE;         % Robot pose error in mobile frame (y-component)
thetaE;     % Robot orientation error with resepect to global x-axis
u1;         % Control variable
u2;         % Control variable
% ===== END VAR ===========================================================

% Suggested value for k2
k2 = 2 * abs(vR) * sqrt(k3);

% State Trafo: Robot pose error in global frame --> mobile frame
xE = cos(theta) * (xR - x) + sin(theta) * (yR - y);
yE = -sin(theta) * (xR - x) + cos(theta) * (yR - y);
thetaE = -(thetaR - theta);

% Control law
u2 = -k2 * thetaE + k3 * vR * yE * sinc(thetaE / pi);
u1 = vR * (cos(thetaE) - 1) + yE * (vThetaR + u2) + k1 * xE;

% Effective control variables
vX = (u1 + vR) * cos(theta);
vY = (u1 + vR) * sin(theta);
vTheta = u2 + vThetaR;
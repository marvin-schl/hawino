%END Terminate scope of FOR, WHILE, SWITCH, TRY, and IF statements.
%   Without END's, FOR, WHILE, SWITCH, TRY, and IF wait for further input.
%   Each END is paired with the closest previous unpaired FOR, WHILE,
%   SWITCH, TRY or IF and serves to terminate its scope.
%
%   END also marks the termination of a function, although in
%   most cases it is optional. END statements are required only in 
%   MATLAB files that employ one or more nested functions. Within such a
%   file, every function (including primary, nested, private, and 
%   subfunctions) must be terminated with an END statement. You can 
%   terminate any function type with END, but doing so is not required
%   unless the file contains a nested function.
%
%   END can also serve as the last index in an indexing expression.  In
%   that context, END = SIZE(X,k) when used as part of the k-th index.
%   Examples of this use are, X(3:end) and X(1,1:2:end-1).  When using END
%   to grow an array, as in X(end+1) = 5, make sure X exists first.
%
%   END(A,K,N) is called for indexing expressions involving the object A
%   when END is part of the K-th index out of N indices.  For example,
%   the expression A(end-1,:) calls A's END method with END(A,1,2).
%
%   See also FOR, WHILE, SWITCH, TRY, IF.

%   Copyright 1984-2015 The MathWorks, Inc.
%   Built-in function.
%wpx = [1,3,4.8,5,4.8,3,1.2,1,0.99];
%wpy = [1,1,1.2,1.5,1.8,2,1.8,1.5,1];

wpy = [0, 0, 1, 5];
wpx = [0, 3, 5, 7];

%wpx = [0, 1, 2];
%wpy = [0, 2, 1];

len = length(wpx);

coeffs = zeros(2,len-1);

for i = 1:len-1
    A = [1 wpx(i);
         1 wpx(i+1)];
    if i == 1 
        a2 = (wpy(2)-wpy(1))/(wpx(2)-wpx(1));
        a1 = wpy(1) - a2*wpx(1);

       coeffs(:,i) = [a1;a2];
    else
        y = [wpy(i);
            wpy(i+1)];
        coeffs(:,i) = A^-1*y;
      
    end
end

g = @(x, coeff) ( coeff(1)+coeff(2).*x);

plot(wpx,wpy,"o")
hold on;
x_vals = [min(wpx):0.01:max(wpx)];
for i = 1:len-1
    if wpx(i) <= wpx(i+1)
        x_vals = [wpx(i):0.01:wpx(i+1)];
    else
        x_vals = [wpx(i+1):0.01:wpx(i)];
    end
    
   plot(x_vals, g(x_vals,coeffs(:,i)))
end



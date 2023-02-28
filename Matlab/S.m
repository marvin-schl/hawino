function [y] = S(x,coeffs)
    tmp = 0;
    for i = 1:length(coeffs)
        tmp = tmp + coeffs(i).*x.^(i-1);
    end
    y = tmp;
end


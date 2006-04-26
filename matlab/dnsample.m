function [y, ny] = dnsample(x, n, M)

y = x(1:M:end);
ny = n;

% ny = n(1:M:end)
% 
% k = find(~ny, 1);
% if size(k, 2)
%     ny = [-(k-1):1:0 1:size(ny, 2)-k]
% end

% S = 0;
% p = -1;
% for k = 1:2:10000
%     p = -p;
%     S = S + p * 1/(k);
% end
% disp(S*4)
n = input('n=?'); 
x = 1:2:(2*n-1); 
y= (-1).^(2:n+1)./x; 
pai = sum(y)*4 
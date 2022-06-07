a = 0; 
b = 1; 
n = input('n=?'); 
h = (b-a)/n; 
x = a:h:b; 
f = sqrt(1-x.*x); 
s = []; 
for k = 1:n 
 s1 = (f(k)+f(k+1))*h/2; 
 s = [s,s1]; 
end 
pai = 4*sum(s);
disp(pai)

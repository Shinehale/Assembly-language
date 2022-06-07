function f = fib(n)
if n>2
    f = fib(n-1)+fib(n-2);
else 
    f = 1;
end

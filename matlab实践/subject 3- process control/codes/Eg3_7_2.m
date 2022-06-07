F = [];
for k = 1:20
    F = [F, fib(k)*fib(k)];
end
sum(F) == fib(20)*fib(21)
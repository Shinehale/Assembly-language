for n = 2:10
    c(n) = cond(hilb(n));
end
format long
c.'
for n = 3:20
    r(n) = rank(magic(n));
end
bar(r) 
grid on 
axis([2,21,0,20])

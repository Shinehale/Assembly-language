function f = fact(n) 
    if n<=1 
        f=1; 
    else 
        f=fact(n-1)*n; 
end
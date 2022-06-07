num = 0;
S = 0;
x = input('Enter a number (end in 0):'); 
while x ~= 0
    S = S+x;
    num = num+1;
    x = input('Enter a number (end in 0):'); 
end
if num > 0
    aver = S / num;
    disp(S)
    disp(aver)
end
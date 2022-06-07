c = input('ÇëÊäÈëÒ»¸ö×Ö·û£º','s');
if c >= 'a' && c <= 'z'
    disp(upper(c))
elseif  c >= 'A' && c <= 'Z' 
    disp(lower(c))
elseif c >= '0' && c <= '9'
    disp(str2double(c)^2)
else 
    disp(c)
end 
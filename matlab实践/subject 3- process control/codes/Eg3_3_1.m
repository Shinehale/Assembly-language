c = input('请输入一个单词：','s');
switch c(1)
    case {'A','E','I','O','U','a','e','i','o','u'} 
        disp([c,'以元音字母开头']);
    otherwise
        disp ([c,'以辅音字母开头']);
end

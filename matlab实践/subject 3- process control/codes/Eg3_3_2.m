g=input('请输入PM2.5值：'); 
switch fix(g) 
    case num2cell(0:34) 
        disp('空气质量优'); 
    case num2cell(35:74) 
        disp('空气质量良好'); 
    case num2cell(75:114) 
        disp('空气质量轻度污染'); 
    case num2cell(115:149) 
        disp('空气质量中度污染'); 
    case num2cell(150:249) 
        disp('空气质量重度污染'); 
    otherwise 
        disp('空气质量严重污染'); 
end
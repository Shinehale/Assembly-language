g=input('������PM2.5ֵ��'); 
switch fix(g) 
    case num2cell(0:34) 
        disp('����������'); 
    case num2cell(35:74) 
        disp('������������'); 
    case num2cell(75:114) 
        disp('�������������Ⱦ'); 
    case num2cell(115:149) 
        disp('���������ж���Ⱦ'); 
    case num2cell(150:249) 
        disp('���������ض���Ⱦ'); 
    otherwise 
        disp('��������������Ⱦ'); 
end
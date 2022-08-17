; 检测点10-3
assume cs:code
code segment
start:	mov ax, 6
	call ax
	inc ax 
	mov bp, sp
	add ax, [bp]	;猜测为: ax = bh 因为[bp]的段地址指向ss

	mov ax, 4c00h
	int 21h
code ends
end start
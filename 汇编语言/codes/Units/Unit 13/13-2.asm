assume cs:code 

code segment

start:	mov ax, cs 
	mov ds, ax
	mov si, offset sqr
	mov ax, 0
	mov es, ax 
	mov di, 200h
	mov cx, offset sqrend - offset sqr
	cld 
	rep movsb

	mov ax, 0
	mov es, ax
	mov word ptr es:[7ch*4], 200h
	mov word ptr es:[7ch*4+2], 0 

	mov ax, 3456
	int 7ch
	add ax, ax
	adc dx, dx

	mov ax, 4c00h
	int 21h


; 传入参数: ax ,高位保存在dx 低位保存在ax中
sqr:	mul ax
	iret
sqrend:	nop 

code ends

end start
;14.4程序
;真的能够实现读取当前日期
assume cs:code
code segment
start:	mov al, 7
	out 70h, al
	in al, 71h

	mov ah, al 
	mov cl, 4
	shr ah, cl
	and al, 00001111b

	add ah, 30h
	add al, 30h

	mov bx, 0b800h
	mov es, bx
	mov byte ptr es:[160*12+40*2], ah
	mov byte ptr es:[160*12+40*2+2], al

	mov ax, 4c00h
	int 21h

code ends

end start
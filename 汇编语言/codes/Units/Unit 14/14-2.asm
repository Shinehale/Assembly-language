;检测点14.2

assume cs:code

code segment 

start:	mov ax, 46
	call calc

	mov ax, 4c00h
	int 21h


;功能：ax * 10 参数： ax 结果:dx 
calc:	push cx 
	push bx 
	mov dx, 0
	mov bx, ax
	mov cl, 3
	shl ax, cl
	add dx, ax
	mov cl, 1
	shl bx, cl
	add dx, bx

calcend:	
	pop bx 
	pop cx 
	ret


code ends
end start
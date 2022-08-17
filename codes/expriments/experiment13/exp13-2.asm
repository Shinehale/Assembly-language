assume cs:code

code segment 

start:	mov ax, cs
	mov ds, ax
	mov si, offset for
	mov ax, 0
	mov es, ax
	mov di, 200h
	mov cx, offset forend - offset for
	cld 
	rep movsb

	mov ax, 0
	mov es, ax
	mov word ptr es:[7ch*4], 200h
	mov word ptr es:[7ch*4+2], 0


	mov ax, 0b800h
	mov es, ax 
	mov di, 160*12

	mov bx, offset s - offset send
	mov cx, 80
s: 	mov byte ptr es:[di], '!'
	add di, 2
	int 7ch
send:	nop

	mov ax, 4c00h
	int 21h


for:	pop bp 
	dec cx 
	jcxz back
	add bp, bx 
back: 	push bp 
	iret
forend:	nop
	
code ends

end start
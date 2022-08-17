assume cs:code
stack segment
	db 128 dup (0)
stack ends


data segment
	dw 0,0
data ends

code segment 
start:	mov ax, stack
	mov ss, ax
	mov sp, 128

	mov ax, data
	mov ds, ax

	mov ax, 0
	mov es, ax 

	push es:[9*4]
	pop ds:[0]
	push es:[9*4+2]
	pop ds:[2]  			;将原来的int 9类型中段例程的入口地址保存

	mov word ptr es:[9*4], offset int9
	mov es:[9*4+2], cs


	mov ax, 0b800h
	mov es, ax 
	mov ah, 'A'

s:	mov es:[160*12+40*2], ah
	call delay
	inc ah 
	cmp ah, 'Z'
	jna s


	mov ax, 0
	mov es, ax 

	push ds:[0]
	pop es:[9*4]
	push ds:[0+2]
	pop es:[9*4+2]

	mov ax, 4c00h
	int 21h

delay:	push ax 
	push dx
	mov dx, 000ch
	mov ax, 0
s1:	sub ax, 1
	sbb dx, 0
	cmp ax, 0
	jne s1
	cmp dx, 0
	jne s1
	pop dx
	pop ax 
	ret

int9:	push ax 
	push bx 
	push es 

	in al, 60h
	pushf
	pushf 
	pop bx 
	and bh, 11111100b
	push bx
	popf 
	call dword ptr ds:[0]

	cmp al, 1
	jne int9ret

	mov ax, 0b800h
	mov es, ax 
	inc byte ptr es:[160*12+40*2+1]

int9ret:	
	pop es
	pop bx 
	pop ax 
	iret


code ends

end start
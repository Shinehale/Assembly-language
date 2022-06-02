; exp 15: 在DOS中，按下"A"键之后，除非不再松开，如果松开，就显示满屏的"A"，其他键照常处理
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
	mov sp, 128 			;设置堆栈

	push cs
	pop ds 
	mov ax, 0
	mov es, ax

	mov si, offset int9
	mov di, 204h
	mov cx, offset int9end - offset int9
	cld 
	rep movsb 			;将代码传送至0:204h


	push es:[9*4]
	pop es:[200h]
	push es:[9*4+2]
	pop es:[202h] 			;将原来的int9地址房子啊0:200和0:202处

	cli 
	mov word ptr es:[9*4], 204h
	mov word ptr es:[9*4+2], 0
	sti  				;将新地址的int9放回原来的位置


	mov ax, 4c00h
	int 21h


int9:	push ax 
	push bx 
	push cx 
	push es 

	in al, 60h


	pushf
	call dword ptr cs:[200h] 		;执行原来的int9程序

	cmp al, 1eh+80h
	jne int9ret

	mov ax, 0b800h
	mov es, ax 
	mov bx, 0
	mov cx, 2000
s:	mov byte ptr es:[bx], 'a'
	add bx, 2
	loop s


int9ret:	
	pop es
	pop cx 
	pop bx 
	pop ax 
	iret

int9end: nop


code ends

end start
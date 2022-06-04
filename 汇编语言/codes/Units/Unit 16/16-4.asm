; 16.3显示字符的程序

assume cs:code,ds:data

data segment


data ends

code segment

start:	
	mov al, 36
	call showbyte


	mov ax, 4c00h
	int 21h

; al 传递要传送的数据

showbyte:	
	jmp short show
	table db '0123456789ABCDEF'

show:	push bx
	push es

	mov ah, al 
	shr ah, 1
	shr ah, 1
	shr ah, 1
	shr ah, 1 			;右移四位,ah得到高四位的值
	and al, 00001111B			;al为低四位的值

	mov bl, ah
	mov bh, 0
	mov ah, table[bx] 		;用高四位作为相对table的偏移

	mov bx, 0b800h
	mov es, bx
	mov es:[160*12+40*2], ah



	mov bl, al
	mov bh, 0
	mov al, table[bx]

	mov es:[160*12+40*2+2], al

	pop es 
	pop bx 

	ret


code ends

end start
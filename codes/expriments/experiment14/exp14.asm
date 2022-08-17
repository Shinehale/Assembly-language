;实验14 访问CMOS RAM
assume cs:code

data segment
	db 'yy/mm/dd hh:mm:ss', '$'
data ends

stack segment
	db 128 dup (0)
stack ends

code segment
start:
	mov ax, stack
	mov ss, ax
	mov sp, 128

	mov ax, data
	mov ds, ax
	

	;显示年月日
	mov si, 0
	mov cx, 3
	mov al, 9
ymd:	push cx
	push ax
	out 70h, al
	in al, 71h

	mov ah, al
	mov cl, 4
	shr ah, cl
	and al, 00001111B

	add ah, 30h
	add al, 30h

	mov ds:[si], ah
	mov ds:[si+1], al
	add si, 3
	pop ax
	dec al
	pop cx
	loop ymd

	;显示时分秒
	mov si, 9
	mov cx, 3
	mov al, 4
hms:	push cx
	push ax
	out 70h, al
	in al, 71h

	mov ah, al
	mov cl, 4
	shr ah, cl
	and al, 00001111B
	add ah, 30h
	add al, 30h

	mov ds:[si], ah
	mov ds:[si+1], al
	add si, 3
	pop ax
	sub al, 2
	pop cx
	loop hms

	mov dx, 0
	;ds:[dx]指向字符串
	mov ah, 9
	int 21h

	mov ax, 4c00h
	int 21h
code ends

end start
assume cs:code, ds: data

data segment 
	db 'welcome to masm!'
	db 00000010B	;绿底
	db 10101100B	;绿底红字
	db 11110001B 	;白底蓝字
data ends


code segment

start:	mov ax, 0B800h
	mov es, ax
	mov bx, 0
	mov ax, data
	mov ds, ax
	jmp show_first

over:	mov ax, 4c00h
	int 21h


show_first:
	mov di, 160*16   	; 160控制的是小窗口行数
	mov cx, 16
	mov bx, 0

s0:	mov al, ds:[bx] 
	mov es:[di], al
	inc di
	inc bx
	mov al, ds:[10h]
	mov es:[di], al
	inc di
	loop s0

show_second:
	mov di, 160*17   	; 160控制的是小窗口行数
	mov cx, 16
	mov bx, 0

s1:	mov al, ds:[bx] 
	mov es:[di], al
	inc di
	inc bx
	mov al, ds:[11h]
	mov es:[di], al
	inc di
	loop s1

show_third:
	mov di, 160*18   	; 160控制的是小窗口行数
	mov cx, 16
	mov bx, 0

s2:	mov al, ds:[bx] 
	mov es:[di], al
	inc di
	inc bx
	mov al, ds:[12h]
	mov es:[di], al
	inc di
	loop s2

	jmp over
code ends
end start
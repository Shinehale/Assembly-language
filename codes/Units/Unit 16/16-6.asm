;16.4 大程序
assume cs:code

code segment

start:	mov ah, 2
	mov al, 00100000b
	call setscreen

	mov ax, 4c00h
	int 21h
; ah传递功能号，al传递颜色值
setscreen:	
	jmp short set

	table dw sub1, sub2, sub3, sub4

set:	push bx 
	
	cmp ah, 3
	ja sret
	mov bl, ah
	mov bh, 0
	add bx, bx

	call word ptr table[bx]

sret:	pop bx 
	ret


;功能一：完成清屏
sub1:	push bx 
	push cx 
	push es 
	mov bx, 0b800h
	mov es, bx 
	mov bx, 0
	mov cx, 2000
sub1s:	
	mov byte ptr es:[bx], ' '
	add bx, 2
	loop sub1s

sub1end:
	pop es 
	pop cx 
	pop bx 
	ret 

;功能二：	设置前景色，设置显存中期当前处于奇地址的属性字节的第0、1、2位
sub2:	
	push bx 
	push cx 
	push es 

	mov bx, 0b800h
	mov es, bx
	mov bx, 1
	mov cx, 2000
sub2s:	
	and al, 00000111b 
	and byte ptr es:[bx], 00000000b 
	or es:[bx], al 
	add bx, 2
	loop sub2s
sub2end:	
	pop es 
	pop cx 
	pop bx 
	ret 
;功能三：	设置背景色，设置显存中期当前处于奇地址的属性字节的第4、5、6位
sub3:	
	push bx 
	push cx 
	push es 
	mov bx, 0b800h
	mov es, bx 
	mov bx, 1
	mov cx, 2000

sub3s:	
	and al, 01110000b 
	and byte ptr es:[bx], 00000000b 
	or es:[bx], al 
	add bx, 2
	loop sub3s

sub3end:	
	pop es 
	pop cx 
	pop bx
;功能四：	向上滚动一行

sub4:	push cx 
	push si 
	push di 
	push es 
	push ds 

	mov si, 0b800h
	mov es, si 
	mov ds, si 
	mov si, 160
	mov di, 0
	cld 
	mov cx, 24

sub4s:	
	push cx 
	mov cx, 160
	rep movsb 

	pop cx 
	loop sub4s

	mov cx, 80
	mov si, 0
sub4s1:	
	mov byte ptr [160*24+si], ' '
	add si, 2
	loop sub4s1

sub4end:	
	pop ds
	pop es 
	pop di 
	pop si 
	pop cx 
	ret 

code ends

end start
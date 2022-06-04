;字符串的输入
assume cs:code

data segment
	db 128 dup (0)
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov si, 0

	mov dh, 12
	mov dl, 39

	call getstr

	mov ax, 4c00h
	int 21h

getstr:	push ax
	
getstrs:	mov ah, 0
	int 16h 				;从16h端口进行读入

	cmp al, 20h
	jb nochar 			;小于20h说明不是字符
	mov ah, 0
	call charstack 			;字符入栈
	mov ah, 2
	call charstack 			;显示栈中的字符
	jmp getstrs

nochar:	cmp ah, 0eh
	je backspace  			;backspace键
	cmp ah, 1ch
	je return 			;Enter键
	jmp getstrs

backspace:	
	mov ah, 1
	call charstack 			;删除栈顶元素
	mov ah, 2
	call charstack
	jmp getstrs

return:	mov al, 0
	mov ah, 0
	call charstack  			;0入栈
	mov ah, 2
	call charstack

	pop ax
	ret


charstack:	
	jmp short charstart

table	dw charpush, charpop, charshow
top	dw 0  				;栈顶

charstart:	
	push ax
	push bx
	push dx
	push ds
	push es
	push si
	push di

	cmp ah, 2
	ja sret 				;大于2，说明是非法操作返回即可
	mov bl, ah 
	mov bh, 0
	add bx, bx
	jmp word ptr table[bx]

charpush:	
	mov bx, top
	mov [si][bx], al
	inc top
	jmp sret

charpop:	cmp top, 0
	je sret
	dec top
	mov bx, top
	mov al, [si][bx]
	jmp sret

charshow:				;根据dh*160+dl*2的位置来展示
	mov bx, 0b800h
	mov es, bx
	mov al, 160
	mov ah, 0
	mul dh
	mov di, ax
	add dl, dl
	mov dh, 0
	add di, dx

	mov bx, 0

charshows:	
	cmp bx, top
	jne noempty
	mov byte ptr es:[di], ' '
	jmp sret

noempty:	mov al, [si][bx]
	mov es:[di], al
	mov byte ptr es:[di+2], ' '
	inc bx
	add di, 2
	jmp charshows

sret:	pop di
	pop si
	pop es
	pop ds
	pop dx
	pop bx
	pop ax
	ret
code ends

end start

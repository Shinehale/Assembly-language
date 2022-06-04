; 16.3直接显示sin值的程序

assume cs:code,ds:data

data segment


data ends

code segment

start:	
	mov al, 120
	call showsin


	mov ax, 4c00h
	int 21h

; ax 传递要传送的角度

showsin:	
	jmp short show

	table dw ag0, ag30, ag60, ag90, ag120, ag150, ag180 	;字符串偏移表
	ag0 db '0',0
	ag30 db '0.5', 0
	ag60 db '0.866', 0
	ag90 db '1', 0
	ag120 db '0.866', 0
	ag150 db '0.5', 0
	ag180 db '0', 0

show:	push bx 
	push es
	push si 
	mov bx, 0b800h
	mov es, bx 

	mov ah, 0
	mov bl, 30 
	div bl 
	mov bl, al 
	mov bh, 0
	add bx, bx 
	mov bx, table[bx]

	mov si, 160*12+40*2
shows:	mov ah, cs:[bx]
	cmp ah, 0
	je showret
	mov es:[si], ah 
	inc bx 
	add si, 2
	jmp short shows 
showret:	
	pop si 
	pop es 
	pop bx 
	ret 



code ends

end start
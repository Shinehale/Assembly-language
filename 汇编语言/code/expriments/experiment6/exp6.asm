assume cs:codeseg, ds: dataseg, ss:stackseg

dataseg segment
	db '1. display      '
	db '2. brows        '
	db '3. replace      '
	db '4. modify       '
dataseg ends

stackseg segment
	dw 0,0,0,0,0,0,0,0
stackseg ends

codeseg segment
start:	mov ax, dataseg
	mov ds, ax
	mov ax, stackseg
	mov ss, ax
	mov sp, 16

	mov cx, 4
	mov bx, 0

s: 	push cx
	mov di, 3
	mov cx, 4

s0:	mov al, [bx+di]
	and al, 11011111B
	mov [bx+di], al
	inc di
	loop s0

	pop cx
	add bx, 10H

	loop s


	mov ax, 4c00h
	int 21h
codeseg ends
end start
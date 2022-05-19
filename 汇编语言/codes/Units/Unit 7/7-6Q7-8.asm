assume cs:codeseg, ds: dataseg, ss:stackseg

dataseg segment
	db 'ibm             '
	db 'dec             '
	db 'dos             '
	db 'vax             '
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

	mov bx, 0 
	mov cx, 4

s0: 	push cx
	mov si, 0
	mov cx, 3

s:	mov al, [bx+si]
	and al, 11011111B
	mov [bx+si], al
	inc si
	loop s

	add bx, 10h 
	pop cx

	loop s0

	mov ax, 4c00h
	int 21h
codeseg ends
end start
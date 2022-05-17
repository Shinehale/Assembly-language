assume cs:codeseg, ds:dataseg

dataseg segment
	db '1. file         '
	db '2. edit         '
	db '3. search       '
	db '4. view         '
	db '5. options      '
	db '6. help         '	
dataseg ends

codeseg segment
start:	mov ax, dataseg
	mov ds, ax

	mov cx, 6h
	mov bx, 3h
	mov si, 0h

 s:	mov al, [bx+si]
 	and al, 11011111B
 	mov [bx+si], al
 	add si, 10h
 	loop s

 	mov ax, 4c00h
 	int 21h
codeseg ends
end start


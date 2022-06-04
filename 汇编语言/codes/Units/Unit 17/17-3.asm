assume cs:code
code segment
start:	mov ax, 0b800h
	mov es, ax 
	mov bx, 0

	mov al, 8
	mov ch, 0
	mov cl, 1
	mov dl, 0
	mov dh, 0
	mov ah, 3
	int 13h

	mov ax, 4c00h
	int 21h
code ends
end start
assume cs:code

code segment
start:	mov ah, 0
	int 16h

	mov ah, 1
	cmp al, 'r'
	je red 
	cmp al, 'g'
	je green
	cmp al, 'b'
	je blue 
	jmp short sret

red:	shl ah, 1
green:	shl ah, 1
blue:	mov bx, 0b800h
	mov es, bx
	mov bx, 1
	mov cx, 2000
s:	and byte ptr es:[bx], 11111000b
	or es:[bx], ah
	add bx, 2 
	loop s 
sret:	mov ax, 4c00h
	int 21h
code ends
end start
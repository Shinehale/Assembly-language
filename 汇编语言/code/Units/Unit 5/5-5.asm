assume cs:code
code segment
	mov ax, 0ffffh
	mov ds, ax

	mov dx, 0
	mov cx, 16
	mov bx, 0

s: 	mov al, [bx]
	mov ah, 0
	add dx, ax
	inc bx
	loop s

	mov ax, 4c00h
	int 21h
code ends
end

assume cs:code

a segment 
	db 1,2,3,4,5,6,7,8
a ends

b segment
	db 1,2,3,4,5,6,7,8
b ends

c segment 
	db 0,0,0,0,0,0,0,0
c ends

code segment

start: 	mov ax, a
	mov ds, ax
	mov ax, b
	mov es, ax

	mov cx, 8
	mov bx, 0

s: 	mov dl, es:[bx]
	mov dh, 0
	add ds:[bx], dx
	inc bx 
	loop s

	mov bx, 0
	mov ax, c
	mov es, ax
	mov cx, 8

s0: 	mov ax, ds:[bx]
	mov es:[bx], ax
	inc bx
	loop s0

	mov ax, 4c00h
	int 21h

code ends

end start
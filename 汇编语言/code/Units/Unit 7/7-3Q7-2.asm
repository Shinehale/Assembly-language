assume cs:code , ds: data 

data segment
	db 'welcome to masm!'
	db '................'
data ends

code segment
start:	mov ax, data
	mov ds, ax
	mov di, 0
	mov si, 0
	mov cx, 8

s:	mov bx, 0[di]
	mov 16[si], bx
	add di, 2
	add si, 2
	loop s

	mov ax, 4c00h
	int 21h
code ends
end start
;检测点9.1(1)
assume cs:codeseg

data segment
	dw 0,0,0,0
data ends

codeseg segment
start:	mov ax, data
	mov ds, ax
	mov bx, 0
	jmp word ptr [bx+1]
codeseg ends

end start
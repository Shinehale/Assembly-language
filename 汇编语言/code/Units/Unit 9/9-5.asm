;检测点9.1(2)
assume cs:codeseg

data segment
	dd 12345678h
data ends

codeseg segment
start:	mov ax, data
		mov ds, ax
		mov bx, 0
		mov word ptr [bx], offset start
		mov [bx+2],	cs
		jmp dword ptr ds:[0]
codeseg ends

end start
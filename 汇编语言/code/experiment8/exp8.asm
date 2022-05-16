assume cs:codeseg
codeseg segment
	
	mov ax, 4c00h
	int 21h		;程序结束

start:	mov ax, 0 	;从此开始
s:	nop 
	nop 		;因为存储的代码是移动相对位移，所以在此处代码替换成
			;jmp short s1时执行的机械码，及相对位移为-6，移动到整个代码段开头

	mov di, offset s
	mov si, offset s2
	mov ax, cs:[si]
	mov cs:[di], ax 	;第一次时将s2处的语句转移到s开头处

s0:	jmp short s

s1:	mov ax, 0
	int 21h		
	mov ax, 0

s2:	jmp short s1
	nop 

codeseg ends
end start
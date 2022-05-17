;名称：divdw
;功能：进行不会产生溢出的除法运算，被除数为dword型，除数为word型，结果为dword型
;参数：(ax)=dword型数据低16位，(dx)=dword型数据高16位，(cx)=除数
;返回：(dx)=结果的高16位，(ax)=结果的低16位，(cx)=余数
;应用举例:计算1000000/10 (F4240H/0AH)
assume cs:code, ds: data

data segment
	dw 0,0,0,0,0,0,0
data ends

code segment 
main:	mov ax, data
	mov ds, ax
	mov ax, 4240h
	mov dx, 00fh
	mov cx, 0ah
	call divdw

	mov ax, 4c00h
	int 21h

divdw:	
	mov bp, cx 	;这样做感觉会有风险
	mov cx, 8
	mov bx, 0
s:	push word ptr ds:[bx]
	add bx, 2
	loop s 		;将用到的存储空间释放

	mov cx, bp
	mov ds:[0], ax 	;ds:[0]存储原来被除数低16位
	mov ds:[2], dx 	;ds:[0]存储原来被除数高16位
	mov ds:[4], cx 	;ds:[0]存储原来除数

	mov ax, ds:[2]
	mov dx, 0
	div cx
	mov ds:[6], ax 	;ds:[6]存储int(H/N)
	mov ds:[8], dx 	;ds:[8]存储rem(H/N)

	mov dx, ds:[8]
	mov ax, ds:[0]
	div cx

	mov cx, dx 	;将余数放入cx中
	mov dx, ds:[6]	;将结果高16位放入dx中，而结果中低16位就是除法得到的结果


	mov bp, cx
	mov bx, 14
	mov cx, 8
s_over:	pop word ptr ds:[bx]
	add bx, -2
	loop s_over
	mov cx, bp
	ret
code ends


end main
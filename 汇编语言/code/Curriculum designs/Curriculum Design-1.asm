;任务: 将实验七中的公司数据在屏幕上显示

; 基本思路: 
; 首先将年份写入render表中
; 再将人员和薪资利用exp10-2中的不溢出除法算出除数，将除数放入data2段中
; 将人员数写入render表中，将薪资数写入render表中
; 将除数写入render表中，最终一次完成渲染

assume ds: data, cs: code,ss: stack, es: render

data segment
	db '1975','1976','1977','1978','1979','1980','1981','1982','1983' 
	db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
	db '1993','1994','1995'
	; above are 21 strings for expressing the 21 years

	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
	dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
	; above are 21 numbers for the sum of the income in 21 years

	dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
	dw 11542,14430,15257,17800
	; above are 21 numbers for the sum of the employees in 21 years
data ends

stack segment
	dw 64 dup (0)
stack ends

data2 segment
	dw 32 dup (0)
data2 ends

render segment
	db 21 dup (' 1975    5937000    17800    333 ')
render ends

code segment
main:	mov ax, data
	mov ds, ax
	mov ax, stack
	mov ss, ax
	mov sp, 128

	call renderYear
	call calculateRemains

	mov ax, 4c00h
	int 21h

renderYear:
	push cx 
	push ax 
	push es 
	push si
	push bx
	push dx
	push di 		;开头缓存用到的寄存器数据

	mov ax, render
	mov es, ax
	mov si, 0 	;将目标渲染首地址写入es:[si]
	mov di, 0

	mov cx, 21
	mov dx, 0
for_RY:
	mov al, ds:[di]
	sub al, 30h
	mov es:[si+1], al 	;第一个字符

	mov al, ds:[di+1]
	sub al, 30h
	mov es:[si+2], al 	;第二个字符

	mov al, ds:[di+2]
	sub al, 30h
	mov es:[si+3], al 	;第三个字符

	mov al, ds:[di+3]
	sub al, 30h
	mov es:[si+4], al 	;第四个字符

	add di, 4
	add si, 32

	loop for_RY




	pop di 
	pop dx 
	pop bx 
	pop si
	pop es 
	pop ax 
	pop cx 		;还原用到寄存器
	ret

calculateRemains:
	push cx 
	push ax 
	push es 
	push si
	push bx
	push dx
	push di 		;开头缓存用到的寄存器数据

	mov ax, data2
	mov es, ax
	mov si, 0 
	mov ax, data
	mov ds, ax
	mov di, 84

	mov cx, 21
	mov bx, 168

for_CalRems:
	push cx 
	mov dx, ds:[di+2]
	mov ax, ds:[di]
	add di, 4
	mov cx, ds:[bx]
	add bx, 2
	call divdw
	mov es:[si], ax
	add si, 2
	pop cx
	loop for_CalRems 		;完成计算商的过程


	pop di 
	pop dx 
	pop bx 
	pop si
	pop es 
	pop ax 
	pop cx 		;还原用到寄存器
	ret


divdw:	
	push bx 
	push bp

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

	pop bp 
	pop bx 
	ret


code ends
end main


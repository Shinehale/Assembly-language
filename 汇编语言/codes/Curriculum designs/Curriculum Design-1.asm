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

data3 segment
	dw 32 dup (0) 	;数据缓存区配合完成数字的展示
data3 ends
render segment
	db 21 dup (' 1975                           ')
	db ' This program is by shine_hale! '
render ends

code segment
main:	mov ax, data
	mov ds, ax
	mov ax, stack
	mov ss, ax
	mov sp, 128

	call renderYear 			;将年份写入render表中
	call calculateRemains 		;计算商并且存入data2段中
	call dtoc 			;将其余数据写入render表中
	call show			;完成渲染

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
	mov es:[si+1], al 	;第一个字符

	mov al, ds:[di+1]
	mov es:[si+2], al 	;第二个字符

	mov al, ds:[di+2]
	mov es:[si+3], al 	;第三个字符

	mov al, ds:[di+3]
	mov es:[si+4], al 	;第四个字符

	add di, 4
	add si, 32

	loop for_RY
over_renderYear:
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
over_calculateRemains:
	pop di 
	pop dx 
	pop bx 
	pop si
	pop es 
	pop ax 
	pop cx 		;还原用到寄存器
	ret

dtoc:	
	push cx 
	push bx 
	push es
	push si 
	push ds 
	push di
	push ax  	;缓存需要的寄存器

	mov cx, 21
	mov di, 84
	mov bp, 9 	
for_dtoc:
	mov dx, ds:[di+2]	;渲染薪资的数值
	mov ax, ds:[di] 
	add di, 4
	call solve

	call render_data3
	add bp, 32
	loop for_dtoc

	mov cx, 21
	mov di, 168
	mov bp, 20 	
for_dtoc0:
	mov dx, 0 	;渲染人数的数值
	mov ax, ds:[di]
	add di, 2
	call solve

	call render_data3
	add bp, 32
	loop for_dtoc0

	mov cx, 21
	mov ax, data2
	mov es, ax
	mov si, 0
	mov bp, 28 	;渲染人平均薪资
for_dtoc1:
	mov dx, 0
	mov ax, es:[si]
	add si, 2
	call solve

	call render_data3
	add bp, 32 
	loop for_dtoc1
over_dtoc:
	pop ax
	pop di 
	pop ds 
	pop si 
	pop es
	pop bx
	pop cx
	ret 		;完成对21个数据处理和移动至render表中

solve:					
	push ax 		;实现对dxax数据的10进制表示并且放入data3段中
	push bx 		;参数：dx 高16位， ax 低16位 
	push cx 
	push es
	push ds 
	push di 
	push si 

	mov bx, data3 	;这里使用bx防止ax数据污染
	mov es, bx
	mov si, 0

	mov cx, 16
empty_solve:
	mov word ptr es:[si], 0
	add si, 2
	loop empty_solve 		;对上次数据进行清空因为已经完成渲染进入render表中

	mov cx, 32
	mov si, 0
for_solve1:
	push cx
	mov cx, ax
	jcxz solve1_over 
	mov cx, 0ah
	call divdw
	mov byte ptr es:[si], cl 	;将本次得到的余数放入data3中
	inc si
	pop cx 
	loop for_solve1
solve1_over:
	pop cx 
	mov bx, 16
solve2_reverse0:
	dec bx 
	mov cx, es:[bx]
	jcxz solve2_reverse0	
	inc bx 			;完成这样的步骤后就是字符串长度

	mov dx, bx 		;利用dx将字符串长度带回

	mov cx, bx
	mov bx, 0
solve2_reverse1:
	mov al, es:[bx]
	mov ah, 0
	inc bx 
	push ax
	loop solve2_reverse1 	;将其依次入栈

	mov cx, dx
	mov bx, 0
solve2_reverse2:
	pop ax
	mov es:[bx], al
	inc bx 
	loop solve2_reverse2  		;完成字符串的反转
over_solve:
	pop si
	pop di
	pop ds
	pop es
	pop cx 
	pop bx 
	pop ax 
	ret

render_data3:
	push ax 			;外部传参地址bp:在render中何处写入data3中的数
	push bx 			;外部传参dx:字符串长度
	push cx
	push ds
	push es
	push di
	push si 

	mov ax, data3
	mov es, ax
	mov si, 0
	mov ax, render
	mov ds, ax

	mov cx, dx 		;将字符串长度给cx
	mov bx, 0
for_renderdata3:
	mov al, es:[si]
	add al, 30h
	mov ds:[si+bp], al
	inc si
	loop for_renderdata3
over_render_data3:
	pop si
	pop di 
	pop es 
	pop ds
	pop cx
	pop bx
	pop ax  
	ret

divdw:	
	push bx 
	push bp 		;缓存用到的寄存器

	mov bp, cx 	;这样做感觉会有风险
	mov cx, 8
	mov bx, 0
s_divdw1:	
	push word ptr ds:[bx]
	add bx, 2
	loop s_divdw1 		;将用到的存储空间缓存

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
divdw_over:
	pop word ptr ds:[bx]
	add bx, -2
	loop divdw_over
	mov cx, bp
	
	pop bp
	pop bx 		;释放原来的数据
	ret

show:
	push dx 
	push cx 

	mov cx, 22
	mov dh, 3
	mov dl, 20
	mov si, 0
for_show0:
	push cx 
	mov cl, 10011111B
	call show_str
	add dh, 1
	add si, 32
	pop cx 
	loop for_show0
over_show:
	pop cx
	pop dx 
	ret

show_str:
	push ax
	push es
	push di
	push ds
	push si 
	push cx 		;将用到的寄存器缓存

	mov ax, 0b800h
	mov es, ax
	mov al, 160
	mul dh
	mov bx, ax
	mov al, 2
	mul dl
	add bx, ax
	mov di, bx 	;完成计算显示开始的位置 es:[di]

	mov ax, render
	mov ds, ax
	mov bp, 0

	mov bl, cl 	;将cl颜色转移到bl中

	mov cx, 32
for_show_str:
	mov al, ds:[bp+si]
	mov es:[di], al
	mov es:[di+1], bl
	add di, 2
	add bp, 1
	loop for_show_str
over_show_str:
	pop cx
	pop si
	pop ds 
	pop di 
	pop es 
	pop ax 		;将用完的寄存器数据还原
	ret

code ends
end main
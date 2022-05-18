;任务: 将实验七中的公司数据在屏幕上显示

; 基本思路: 
; 首先将年份写入render表中
; 再将人员和薪资利用exp10-2中的不溢出除法算出除数，将除数放入data2段中
; 将人员数写入render表中，将薪资数写入render表中
; 将除数写入render表中，最终一次完成渲染

assume ds: data, cs: code,ss: stack, es: table

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
	mov ax, 4c00h
	int 21h

code ends
end main


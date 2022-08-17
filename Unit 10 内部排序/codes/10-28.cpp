#include <stdio.h>
#include <stdlib.h>

void BiBubble(int r[], int n)
{
	int flag, i=0, j, temp;
	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		for(j=n-i-1;j>i;j--)//逆序冒泡，找最小
			if (r[j - 1] > r[j])
			{
				flag = 1;
				temp = r[j];
				r[j] = r[j - 1];
				r[j - 1] = temp;
			}
		for (j = i; j < n - i-1; j++)//正序冒泡，找最大
			if (r[j] > r[j + 1])
			{
				flag = 1;
				flag = 1;
				temp = r[j];
				r[j] = r[j + 1];
				r[j + 1] = temp;
			}
		i++;	 
	}
}

int main()
{
	int a[10];
	int i, j;
	for (i = 0, j = 10; i < 10; i++, j--)
		a[i] = j;
	BiBubble(a, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}

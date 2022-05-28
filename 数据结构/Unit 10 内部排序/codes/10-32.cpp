#include<stdio.h>

#define RED 1
#define WHITE 2
#define BLUE 3

void swap(int *m ,int *n)
{
	int p;
	p = *m;
	*m = *n;
	*n = p;
}

void __nationflag(int arr[], int l, int r)
{
	int lt = l; //等于2的部分第一个元素的位置
	int gt = r; //大于2的部分的前一个元素的位置
	int i = l;
	while(i <= gt)
	{
		if(arr[i] < 2) //小于2的 就与 等于2的部分的第一个元素交换
		{
			swap(&arr[i],&arr[lt]);
			i++;   //继续扫描下一个元素
			lt++; //然后等于2的部分坐标要加一
		}
		else if(arr[i] > 2)
		{
			swap(&arr[i],&arr[gt]); //大于2的 就与 gt所指的元素交换
			gt --;   //gt指针向前移动一步，此时i并不移动，因为并不知道交换过去的是否小于2
		}

		else
		{
			i++;
		}
	}
}

void nationflag(int arr[],int n)
{
	__nationflag(arr,0,n-1);

}

void printArray(int a[],int n)
{
	int i;
	for(i = 0;i < n ; i++)
	{
		printf("%d ",a[i]);

	}
	printf("\n");

}

int main(int argc, char const *argv[])
{
	int arr[12] = {2,3,1,3,2,3,1,1,1,3,2,2};
	nationflag(arr,12);

	printArray(arr,12);
	
	return 0;
}

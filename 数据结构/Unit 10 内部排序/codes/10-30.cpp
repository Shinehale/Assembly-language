#include<stdio.h>

#define FALSE 0
#define TRUE 1

void printArray(int a[],int n);

typedef struct 
{
	int low;
	int high;
	
}SNode;

void swap(int *i,int *j) {
	int p;
	p = *i;
	*i = *j;
	*j = p;
}

int partition(int arr[],int low,int high) {
	int aim;
	aim = arr[low];

	while(low < high){
		while(low < high && arr[high] >= aim) --high; //先从high开始
		arr[low] = arr[high];	
		while(low < high && arr[low] <= aim) ++low;
		arr[high] = arr[low];
	}

	arr[low] = aim;

	return low;

}


void compareSort(int arr[],int low,int high){
	int remark;
	int num = high - low + 1;
	do{
		remark = FALSE;
		for(int i = low; i < num - 1 ; i++){

			if( arr[i] > arr[i+1] ){
				swap( &arr[i] , &arr[i+1] );
				remark = TRUE;
			}
		}

		num -- ;

	}while(remark);

}

void __quicksort2(int arr[],int low,int high)
{
	int tag = TRUE;  //判断序列是否有序
	SNode Stack[100];
	int lnum,rnum;
	int position;
	int i,j;
	int count = 0; //记录栈中元素,要初始一下元素

	while(1)//这里不是tag了
	{
		//先判断待排记录
		if(high - low + 1 <= 3){
			compareSort(arr,low,high);
			//先判断栈里是否有元素，有就弹出
			if(count){
				low = Stack[count].low;
				high = Stack[count].high;
				count --;
			}
			else
				break;
		}
		else{
			position = partition(arr,low,high);
			lnum = position - low;
			rnum = high - position;

			count++;

			if( lnum <= rnum ) //左边的元素少，右边入栈
			{
				Stack[count].low = position + 1;
				Stack[count].high = high;
				high = position - 1;
			}
			else{
				Stack[count].low = low;
				Stack[count].high = position - 1;
				low = position + 1;
			}

		}
	}
}

		

void quicksort2(int arr[],int n)
{
	__quicksort2(arr,0,n-1);

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
	int a[8]={7,3,6,2,9,5,1,4};
	quicksort2(a,8);

	printArray(a,8);
	
	return 0;
}


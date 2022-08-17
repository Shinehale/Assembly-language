#include <stdio.h>
#include <stdlib.h>
#define max 10
typedef struct
{
	int key;
	//...
}RedType;

typedef struct
{
	RedType r[max];// r[0]用作哨兵单元
	int length;
}SqList;


void ti_31(SqList& L)
{
	int i = 0, j = L.length;
	while (i != j)
	{
		while (i < j && L.r[i].key < 0)
			i++;
		if (i < j)
			L.r[0] = L.r[i];
		while (i < j && L.r[j].key >= 0)
			j--;
		if (i < j)
		{
			L.r[i++] = L.r[j];
			L.r[j] = L.r[0];
		}
	}
}

int main()
{
	SqList l;
	l.length = 3;
	l.r[1].key = 3;
	l.r[2].key = -2;
	l.r[3].key = -9;
	ti_31(l);
	for (int i = 1; i < 4; i++)
		printf("%d ", l.r[i].key);
}


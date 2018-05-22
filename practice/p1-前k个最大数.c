/*
	返回长度为n的数组前k个最大数
*/

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"


#define LENGTH 100000
#define K 1000


void pop(int i[], int len)
{
	int x, y, c;

	for (x = len; x >= 0; x--)
	{
		
		for (y = 0; y < x-1; y++)
		{
			if (i[y] < i[y+1])
			{
				c = i[y];
				i[y] = i[y + 1];
				i[y + 1] = c;
			}
		}
	}
}


//冒泡排序并返回前k个最大数
void f1(int i[], int len, int o[], int k)
{
	int x;

	pop(i, len);
	for (x = 0; x < k; x++)
	{
		o[x] = i[x];
	}
}


//选定前k个数冒泡排序得到数据，k到n个之间的数插入数组
void f2(int i[], int len, int o[], int k)
{
	int x, y, tmp;

	for (x = 0; x < k; x++)
	{
		o[x] = i[x];
	}
	pop(o, k);

	for (x = k; x < len; x++)
	{
		if (i[x] < o[k-1])
		{
			continue;
		}
		else
		{
			o[k - 1] = i[x];
			for (y = k - 1; y > 0; y--)
			{
				if (o[y] > o[y - 1])
				{
					tmp = o[y];
					o[y] = o[y - 1];
					o[y - 1] = tmp;
				}
			}
		}
		
	}
}

//
//void main()
//{
//	int a1[LENGTH], o1[K];
//	int a2[LENGTH], o2[K];
//	time_t t1, t2;
//
//	random_array(a1, LENGTH);
//	random_array(a2, LENGTH);
//
//
//	t1 = time(NULL);
//	f1(a1, LENGTH, o1, K);
//	t2 = time(NULL);
//	//print_array(o1, K);
//	printf("used time: %is\n", t2 - t1);
//
//	t1 = time(NULL);
//	f2(a2, LENGTH, o2, K);
//	t2 = time(NULL);
//	//print_array(o2, K);
//	printf("used time: %is\n", t2 - t1);
//
//
//	system("pause");
//}

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "../srcs/list.h"


#define BUCKET_CAPACITY 2048 //2**11


void InitArray(int array[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		array[i] = 0;
	}
}

void BucketSort(int array[], int length)
{
	int i, tmp;
	int bucket[BUCKET_CAPACITY];


	InitArray(bucket, BUCKET_CAPACITY);
	// …®√Ë¥˝≈≈–Ú ˝◊È
	for (i = 0; i < length; i++)
	{
		tmp = array[i];
		if (tmp > BUCKET_CAPACITY)
		{
			fprintf(stderr, "array number %i is too big", tmp);
			exit(1);
		}
		bucket[tmp] += 1;
	}
	// …®√ËÕ∞
	tmp = 0;
	for (i = 0; i < BUCKET_CAPACITY; i++)
	{
		while (bucket[i] > 0)
		{
			array[tmp] = i;
			bucket[i] -= 1;
			tmp++;
		}
	}

}




int main()
{
	int array[] = { 101, 68, 0, 444, 3 };

	BucketSort(array, 5);
	print_array(array, 5);
	

	PAUSE;
}

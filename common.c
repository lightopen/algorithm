#include <stdio.h>
#include <time.h>
#include "common.h"




void random_array(int a[], int len)
{
	int x, y;

	srand(time(NULL));
	for (x = 0; x < len; x++)
	{
		a[x] = rand();
	}

}


void print_array(int a[], int len)
{
	int x;

	for (x = 0; x<len; x++)
	{
		printf("array[%i]: %i\n", x, a[x]);
	}
}
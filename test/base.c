#include <stdio.h>



int main_ret = 0;
int test_count = 0;
int test_pass = 0;



void TestCompleted()
{
	printf("\n--------TEST RESULT---------------\n");
	printf("%i case, %i pass(%i%%)\n", test_count, test_pass, test_pass * 100 / test_count);
	printf("result: %s\n", main_ret ? "faile" : "pass");
}
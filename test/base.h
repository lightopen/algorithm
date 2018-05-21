#pragma once


#ifndef _BASE_H

#define _BASE_H

int main_ret;
int test_count;
int test_pass;


#ifndef NULL
#define NULL (void *)0
#endif // !NULL



#define ASSERT_BASE(equality, expect, actual, expression) \
	do \
	{ \
		test_count += 1; \
		printf("%s:%d: ", __FILE__, __LINE__);\
		if (equality) \
		{ \
			printf("ok\n");\
			test_pass += 1; \
		} \
		else \
		{ \
			printf("%s\n", expression);\
            main_ret = 1;\
        }\
	} while(0)	

#define ASSERT_IS_NULL(actual) ASSERT_BASE( (actual) == (NULL), 0, actual, "expect NULL")

#define ASSERT_IS_NOT_NULL(actual) ASSERT_BASE((actual) != (NULL), 0, actual, "expect not NULL")

#define ASSERT_TRUE(equality) ASSERT_BASE(equality, 0, 0, "expect true expression")

#define ASSERT_FALSE(equality) ASSERT_BASE((! (equality)), 0, 0, "expect false expression")


void TestCompleted();

#endif // !_BASE_H
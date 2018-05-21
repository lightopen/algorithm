#include <stdio.h>
#include "base.h"
#include "../srcs/list.h"
#include "test_list.h"

extern main_ret;
extern test_count;
extern test_pass;


static void TestAllocNode()
{
	Postion p;
	p = AllocNode();

	ASSERT_IS_NOT_NULL(p);
	ASSERT_IS_NULL(p->next);

	DeleteList(p);
}

static void TestMakeEmptyListWithLenght()
{
	int length = 10, i;
	List list;
	Postion p;

	list = MakeEmptyListWithLenght(length);
	
	ASSERT_IS_NOT_NULL(list);

	p = list;
	for (i=0; i< length; i++)
	{
		p = p->next;
		ASSERT_IS_NOT_NULL(p);
		ASSERT_TRUE(p->element == 0);		
	}

	ASSERT_IS_NULL(p->next);

	DeleteList(list);
}


static void TestMakeEmpty()
{
	int length = 10, i=0;
	List list;
	Postion p;

	list = MakeEmptyListWithLenght(length);
	p = list->next;
	while (p != NULL)
	{
		p->element = i;
		p = p->next;
		i += 1;
	}
	MakeEmpty(list);
	p = list->next;
	while (p != NULL)
	{
		ASSERT_TRUE(p->element == 0);
		p = p->next;
	}

	DeleteList(list);
}



static void TestIsEmpty()
{
	List list1, list2;

	list1 = MakeEmptyListWithLenght(0);
	list2 = MakeEmptyListWithLenght(1);

	ASSERT_TRUE(IsEmpty(list1));
	ASSERT_FALSE(IsEmpty(list2));

	DeleteList(list1);
	DeleteList(list2);
}

static void TestIsLast()
{
	List list;
	Postion p;

	list = MakeEmptyListWithLenght(2);
	
	p = list->next;
	ASSERT_FALSE(IsLast(p, list));
	p = p->next;
	ASSERT_TRUE(IsLast(p, list));

	DeleteList(list);
}


static void TestFind()
{
	List list;
	Postion p;
	ElementType e = 1;
	
	list = MakeEmptyListWithLenght(2);
	p = Find(e, list);
	ASSERT_IS_NULL(p);
	p = list->next;
	p->element = e;
	ASSERT_TRUE(p == Find(e, list));
	p->next->element = e;
	ASSERT_TRUE(p == Find(e, list));

	DeleteList(list);
}


static void TestDelete()
{
	List list;
	ElementType e = 2;

	list = MakeEmptyListWithLenght(2);
	list->next->element = e;
	Delete(e, list);
	ASSERT_TRUE(list->next->element != e);
	ASSERT_TRUE(IsLast(list->next, list));

	DeleteList(list);
}

static void TestFindPrevious()
{
	List list;
	Postion p;
	ElementType e=10;

	list = MakeEmptyListWithLenght(3);
	p = list->next;
	p->next->element = e;
	ASSERT_TRUE(FindPrevious(e, list) == p);
	ASSERT_IS_NULL(FindPrevious(e+1, list));

	DeleteList(list);
}


static void TestInsert()
{
	List list;
	Postion p;
	ElementType e = 1;

	list = MakeEmptyListWithLenght(2);
	p = list->next->next;
	ASSERT_IS_NULL(p->next);
	Insert(e, list, p);
	ASSERT_IS_NOT_NULL(p->next);
	ASSERT_TRUE(p->next->element == e);

	DeleteList(list);
}


static void TestDeleteList()
{
	;
}

static void TestHeader()
{
	List list;

	list = MakeEmptyListWithLenght(2);
	ASSERT_TRUE(list == Header(list));
	
	DeleteList(list);
}


static void TestFirst()
{
	List list;
	Postion p;

	list = MakeEmptyListWithLenght(2);
	p = list->next;
	ASSERT_TRUE(First(list) == p);

	DeleteList(list);
}


static void TestAdvance()
{
	List list;
	Postion p;

	list = MakeEmptyListWithLenght(2);
	p = list->next;

	ASSERT_TRUE(Advance(p) == p->next);
	p = p->next;
	ASSERT_IS_NULL(Advance(p));

	DeleteList(list);
}


static void TestRetrieve()
{
	List list;
	Postion p;
	ElementType e = 10;

	list = MakeEmptyListWithLenght(2);
	p = list->next;
	p->element = e;
	ASSERT_TRUE(Retrieve(p) == e);
	ASSERT_TRUE(Retrieve(p->next) == 0);
	
	DeleteList(list);
}


void TestListMain()
{
	TestAllocNode();
	TestMakeEmptyListWithLenght();
	TestMakeEmpty();
	TestIsEmpty();
	TestIsLast();
	TestFind();
	TestDelete();
	TestFindPrevious();
	TestInsert();
	TestDeleteList();
	TestHeader();
	TestFirst();
	TestAdvance();
	TestRetrieve();


	TestCompleted();
}

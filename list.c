#include <stdio.h>
#include <stdlib.h>
#include "list.h"



struct Node
{
	ElementType element;
	Postion next;
};


Postion AllocNode()
{
	Postion p;

	p = (Postion)malloc(sizeof(struct Node));
	if (p == NULL)
		exit(1);
	return p;
}


List MakeEmptyListWithLenght(int length)
{
	Postion p, tmp;
	List l;
	int i;

	l = p = AllocNode();
	for (i = 0; i < length; i++)
	{
		tmp = AllocNode();
		tmp->element = 0;
		p->next = tmp;
		p = p->next;
	}

	return l;
}


List MakeEmpty(List L) 
{
	Postion p;
	p = L->next;
	while (p != NULL)
	{
		p->element = 0;
		p = p->next;
	}
	return L;
}


int IsEmpty(List L)
{
	return L->next == NULL;
}


int IsLast(Postion P, List L)
{
	return P->next == NULL;
}


Postion Find(ElementType X, List L)
{
	Postion p;
	p = L->next;
	while (p != NULL)
	{
		if (p->element == X)
			break;
		p = p->next;
	}
	return p;
}


void Delete(ElementType X, List L)
{
	Postion p, tmp;
	p = FindPrevious(X, L);
	if (! IsLast(p, L))
	{
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
	}
}


Postion FindPrevious(ElementType X, List L)
{
	Postion p;
	p = L;
	while (p->next != NULL)
	{
		if (p->next->element == X)
			break;
		p = p->next;

	}
	return p;
}


void Insert(ElementType X, List L, Postion P)
{
	Postion tmp;
	tmp = (Postion)malloc(sizeof(struct Node));
	if (tmp == NULL)
		exit(1);

	tmp->element = X;
	tmp->next = P->next;
	P->next = tmp;
}


void DeleteList(List L)
{
	Postion p, tmp;
	p = L;
	while (p != NULL)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}

}


Postion Header(List L)
{
	return L;
}


Postion First(List L)
{
	return L->next;
}


Postion Advance(Postion P)
{
	return P->next;
}


ElementType Retrieve(Postion P)
{
	return P->element;
}




int main()
{
	;
}


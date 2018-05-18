#include <stdio.h>
#include "list.h"
#include <stdlib.h>


List MakeEmpty(List L) 
{
	Postion p;
	p = L->next;
	while (p != NULL)
	{
		p->element = 0;
		p = p->next;
	}
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
		er

	tmp->element = X;
	tmp->next = P->next;
	P->next = tmp;
}
void DeleteList(List L);
Postion Header(List L);
Postion First(List L);
Postion Advance(Postion p);
ElementType Retrieve(Postion P);








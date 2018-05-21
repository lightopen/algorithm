#pragma once

#ifndef _LIST_H

#define _LIST_H

typedef int ElementType;
struct  Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Postion;


// 自定义接口
List MakeEmptyListWithLenght(int length);
Postion AllocNode();


// 以下为书本接口
void MakeEmpty(List L); // 返回值List改为void
int IsEmpty(List L);
int IsLast(Postion P, List L);
Postion Find(ElementType X, List L);
void Delete(ElementType X, List L);
Postion FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Postion P);
void DeleteList(List L);
Postion Header(List L);
Postion First(List L);
Postion Advance(Postion P);
ElementType Retrieve(Postion P);



#endif // !_LIST_H

struct Node
{
	ElementType element;
	Postion next;
};

#include<iostream>
using namespace std;
struct node
{
	int data;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTai;
};
void CreateList(list& l)
{
	l.pHead = NULL;
	l.pTai = NULL;
}
bool IsEmty(list l)
{
	if (l.pHead == NULL)
		return true;
	else
		return false;
}
node* GetNode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->data = n;
	p->pNext = NULL;
	return p;
}
void GetList(list& l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTai = p;
	}
	else
	{
		l.pTai->pNext = p;
		l.pTai = p;
	}
}
void push(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTai = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
int pop(list& l, int& a)
{
	node* p;
	if (IsEmty(l) != 1)
	{
		p = l.pHead;
		a = p->data;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTai = NULL;
		delete p;
		return a;
	}
}
int main()
{
	list l;
	node* p;
	CreateList(l);
	push(l, p);
	int a;
	pop(l, a);
	return 0;
}
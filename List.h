#ifndef LIST_H
#define LIST_H

#include "NODE.h"

template <class type>
class List
{
private:
	NODE<type>* head;
public:
	List();
	NODE<type>* prepend(type X);
	NODE<type>* insert(type X, int pos);
	void deleteNODE(NODE<type>*& X);
	void deleteFirst();
	void deleteAt(int pos);
	void deleteList();
	bool reverse();
	~List();
};

template<class type>
List<type>::List()
{
	head = nullptr;
}

template<class type>
NODE<type>* List<type>::prepend(type X)
{
	NODE<type>* newNODE = new (nothrow) NODE<type>(X, nullptr);
	if (newNODE == nullptr) { return nullptr; }
	if (head == nullptr)
	{
		head = newNODE;
		return newNODE;
	}
	newNODE->next = head;
	head = newNODE;
	return newNODE;
}

template<class type>
NODE<type>* List<type>::insert(type X, int pos)
{
	if (pos < 0) { return nullptr; }

	else if (pos == 0)
	{
		return prepend(X);
	}
	NODE<type>* p = head;
	for (int i = 1; i < pos && p != nullptr; i++)
	{
		p = p->next;
	}
	if (p == nullptr) { return nullptr; }
	NODE<type>* newNODE = new (nothrow) NODE<type>(X);
	if (newNODE == nullptr) { return nullptr; }
	newNODE->next = p->next;
	p->next = newNODE;
	return newNODE;
}

template<class type>
void List<type>::deleteNODE(NODE<type>*& X)
{
	if (X == nullptr) { return; }
	X->next = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
void List<type>::deleteFirst()
{
	if (head == nullptr) { return; }
	NODE<type>* p = head;
	head = head->next;
	deleteNODE(p);
}

template<class type>
void List<type>::deleteAt(int pos)
{
	if (pos < 0 || head == nullptr) { return; }
	else if (pos == 0) 
	{
		deleteFirst();
		return;
	}
	NODE<type>* p = head;
	for (int i = 1; i < pos && p != nullptr; i++)
	{
		p = p->next;
	}
	if (p == nullptr) { return; }
	NODE<type>* q = p->next;
	if (q != nullptr)
	{
		p->next = q->next;
		deleteNODE(q);
	}
}

template<class type>
void List<type>::deleteList()
{
	if (head == nullptr) { return; }
	while (head != nullptr)
	{
		deleteFirst();
	}
}

template<class type>
bool List<type>::reverse()
{
	List<type> L2;
	NODE<type>* p = head;
	bool test = 1;
	while (p != nullptr)
	{
		type X = p->data;
		if (prepend(X) == nullptr)
		{
			test = 0;
			L2.deleteList();
			break;
		}
		p = p->next;
	}
	if (test)
	{
		deleteList();
		head = L2.head;
		return true;
	}
	return false;
}

template<class type>
List<type>::~List()
{
	cout << "deleted" << endl;
	if (head == nullptr)
	{
		return;
	}
	while (head != nullptr)
	{
		deleteFirst();
	}
}

#endif

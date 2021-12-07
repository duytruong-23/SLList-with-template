#ifndef LIST_H
#define LIST_H

#include "SLNode.h"

template <class type>
class SLList
{
private:
	SLNode<type>* Head;
	SLNode<type>* Tail;
public:
	SLList();
	bool is_Empty();
	SLNode<type>* createNewNode(const type& data, SLNode<type>* next = nullptr);
	SLNode<type>* prepend(const type& X);
	SLNode<type>* append(const type& X);
	SLNode<type>* insert(const type& X, const int& pos);
	void deleteNode(SLNode<type>*& X);
	void deleteFirst();
	void deleteAt(const int& pos);
	void deleteList();
	void reverse();
	~SLList();
};

template<class type>
SLList<type>::SLList()
	:Head(nullptr), Tail(nullptr)
{
}

template<class type>
bool SLList<type>::is_Empty()
{
	return (Head == nullptr);
}

template<class type>
SLNode<type>* SLList<type>::createNewNode(const type& data, SLNode<type>* next)
{
	SLNode<type>* newNode = new (std::nothrow) SLNode<type>(data, next);
	return newNode;
}

template<class type>
SLNode<type>* SLList<type>::prepend(const type& X)
{
	SLNode<type>* newNode = createNewNode(X);
	if (newNode == nullptr) { return nullptr; }
	if (is_Empty())
	{
		Head = Tail = newNode;
		return newNode;
	}
	newNode->Next = Head;
	Head = newNode;
	return newNode;
}

template <class type>
SLNode<type>* SLList<type>::append(const type& X)
{
	SLNode<type>* newNode = createNewNode(X);
	if (newNode == nullptr) { return nullptr; }
	if (is_Empty())
	{
		Head = Tail = newNode;
		return newNode;
	}
	Tail->Next = newNode;
	Tail = newNode;
	return newNode;
}


template<class type>
SLNode<type>* SLList<type>::insert(const type& X, const int& pos)
{
	if (pos < 0) { return nullptr; }

	else if (pos == 0)
	{
		return prepend(X);
	}
	SLNode<type>* p = Head;
	int i = 1;
	while (i < pos && p != nullptr)
	{
		p = p->Next;
		i++;
	}
	if (p == nullptr) { return nullptr; }
	SLNode<type>* newNode = createNewNode(X);
	if (newNode == nullptr) { return nullptr; }
	newNode->Next = p->Next;
	p->Next = newNode;
	if (Tail == p)
	{
		Tail = newNode;
	}
	return newNode;
}

template<class type>
void SLList<type>::deleteNode(SLNode<type>*& X)
{
	if (X == nullptr) { return; }
	X->Next = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
void SLList<type>::deleteFirst()
{
	if (is_Empty()) { return; }
	SLNode<type>* p = Head;
	Head = Head->Next;
	deleteNode(p);
}

template<class type>
void SLList<type>::deleteAt(const int& pos)
{
	if (pos < 0 || Head == nullptr) { return; }
	else if (pos == 0)
	{
		deleteFirst();
		return;
	}
	SLNode<type>* p = Head;
	int i = 1;
	while (i < pos && p != nullptr)
	{
		p = p->Next;
		i++;
	}
	if (p == nullptr) { return; }
	SLNode<type>* q = p->Next;
	if (Tail == q)
	{
		Tail = p;
	}
	if (q != nullptr)
	{
		p->Next = q->Next;
		deleteNode(q);
	}
}

template<class type>
void SLList<type>::deleteList()
{
	while (!is_Empty())
	{
		SLNode<type>* p = Head;
		Head = Head->Next;
		deleteNode(p);
	}
	Tail = nullptr;
}

template<class type>
void SLList<type>::reverse()
{
	if (Head == nullptr) { return; }
	SLNode<type>* Head_2 = Head->Next;
	Head->Next = nullptr;
	Tail = Head;
	while (Head_2 != nullptr)
	{
		SLNode<type>* Cur = Head_2;
		Head_2 = Head_2->Next;
		Cur->Next = Head;
		Head = Cur;
	}
}

template<class type>
SLList<type>::~SLList()
{
	deleteList();
}

#endif
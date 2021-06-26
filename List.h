#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <class type>
class List
{
private:
	Node<type>* Head;
public:
	List();
	Node<type>* prepend(type X);
	Node<type>* append(type X);
	Node<type>* insert(type X, int pos);
	void deleteNode(Node<type>*& X);
	void deleteFirst();
	void deleteAt(int pos);
	void deleteList();
	void reverse();
	~List();
	void print();
};

template<class type>
List<type>::List()
{
	Head = nullptr;
}

template<class type>
Node<type>* List<type>::prepend(type X)
{
	Node<type>* newNode = new (std::nothrow) Node<type>(X, nullptr);
	if (newNode == nullptr) { return nullptr; }
	newNode->Next = Head;
	Head = newNode;
	return newNode;
}

template <class type>
Node<type>* List<type>::append(type X)
{
	Node<type>* newNode = new (std::nothrow) Node<type>(X);
	if (newNode == nullptr) { return nullptr; }
	if (Head == nullptr)
	{
		Head = newNode;
		return newNode;
	}
	Node<type>* p = Head;
	while (p->next != nullptr)
	{
		p = p->Next;
	}
	p->Next = newNode;
	return newNode;
}


template<class type>
Node<type>* List<type>::insert(type X, int pos)
{
	if (pos < 0) { return nullptr; }

	else if (pos == 0)
	{
		return prepend(X);
	}
	Node<type>* p = Head;
	int i = 1;
	while (i < pos && p != nullptr)
	{
		p = p->Next;
		i++;
	}
	if (p == nullptr) { return nullptr; }
	Node<type>* newNode = new (std::nothrow) Node<type>(X);
	if (newNode == nullptr) { return nullptr; }
	newNode->Next = p->Next;
	p->Next = newNode;
	return newNode;
}

template<class type>
void List<type>::deleteNode(Node<type>*& X)
{
	if (X == nullptr) { return; }
	X->Next = nullptr;
	delete X;
	X = nullptr;
}

template<class type>
void List<type>::deleteFirst()
{
	if (Head == nullptr) { return; }
	Node<type>* p = Head;
	Head = Head->Next;
	deleteNode(p);
}

template<class type>
void List<type>::deleteAt(int pos)
{
	if (pos < 0 || Head == nullptr) { return; }
	else if (pos == 0) 
	{
		deleteFirst();
		return;
	}
	Node<type>* p = Head;
	int i = 1;
	while (i < pos && p != nullptr)
	{
		p = p->Next;
		i++;
	}
	if (p == nullptr) { return; }
	Node<type>* q = p->Next;
	if (q != nullptr)
	{
		p->next = q->Next;
		deleteNode(q);
	}
}

template<class type>
void List<type>::deleteList()
{
	if (Head == nullptr) { return; }
	while (Head != nullptr)
	{
		deleteFirst();
	}
}

template<class type>
void List<type>::reverse()
{
	if (Head == nullptr) { return; }
	Node<type>* Head_2 = Head->Next;
	Head->Next = nullptr;
	while (Head_2 != nullptr)
	{
		Node<type>* Cur = Head_2;
		Head_2 = Head_2->Next;
		Cur->Next = Head;
		Head = Cur;
	}
}

template<class type>
List<type>::~List()
{
	if (Head == nullptr)
	{
		return;
	}
	while (Head != nullptr)
	{
		deleteFirst();
	}
}

template<class type>
void List<type>::print()
{
	Node<type>* p = Head;
	while (p != nullptr)
	{
		std::cout << p->getData()<<" ";
		p = p->Next;
	}
	std::cout << "\n";
}

#endif

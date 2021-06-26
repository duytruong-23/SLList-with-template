#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<class type>
class List;

template <class type>
class Node
{
	friend class List<type>;
private:
	type Data;
	Node<type>* Next;
public:
	Node(type data, Node<type>* next = nullptr);
	~Node();
	type getData();
};

template <class type>
Node<type>::Node(type Data, Node<type>* Next)
{
	this->Data = Data;
	this->Next = Next;
}

template <class type>
Node<type>::~Node()
{
	
}

template<class type>
type Node<type>::getData()
{
	return Data;
}
#endif

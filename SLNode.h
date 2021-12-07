#ifndef SLNODE_H
#define SLNODE_H

#include <iostream>

using namespace std;

template<class type>
class SLList;

template <class type>
class SLNode
{
	friend class SLList<type>;
private:
	type Data;
	SLNode<type>* Next;
public:
	SLNode(const type& data, SLNode<type>* next = nullptr);
	~SLNode();
	type getData();
};

template <class type>
SLNode<type>::SLNode(const type& data, SLNode<type>* next)
	:Data(data), Next(next)
{
}

template <class type>
SLNode<type>::~SLNode()
{
}

template<class type>
type SLNode<type>::getData()
{
	return Data;
}
#endif

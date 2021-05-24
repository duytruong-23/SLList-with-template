#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<class type>
class List;

template <class type>
class NODE
{
	friend class List<type>;
private:
	type data;
	NODE<type>* next;
public:
	NODE(type data, NODE<type>* next = nullptr);
	~NODE();
};

template <class type>
NODE<type>::NODE(type data, NODE<type>* next)
{
	this->data = data;
	this->next = next;
}

template <class type>
NODE<type>::~NODE()
{
	
}
#endif

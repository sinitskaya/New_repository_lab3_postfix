#pragma once
#include <iostream>
using namespace std;

template<class VT>
class Node
{
public:
	Node *pNext;
	VT key;
	Node();
	Node(const VT & key1);
	~Node();
};

template <class VT> 
Node<VT>:: Node()
{
	pNext = 0;
}

template <class VT> 
Node <VT>:: Node(const VT & key1)
{
	key = key1;
	pNext = 0;
}

template <class VT> 
Node<VT>:: ~Node()
{}
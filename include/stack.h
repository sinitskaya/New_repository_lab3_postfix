#include "list.h"

template <class VT>
class Stack
{
private:
	List<VT> *list;
public:
	Stack();
	Stack(const Stack<VT> & S);
	~Stack();
	int IsEmpty()const;       //проверка на пустоту
	int IsFull()const;        //проверка на полноту
	void Push(const VT a);    //положить в стек  
	VT Pop();                 //извлечь из стека
	VT GetValue();            //получить значение, не извлекая
	void Print()const;
	int operator == (const Stack<VT> & S)const;
	int operator != (const Stack<VT> & S)const;
};

template <class VT>
Stack<VT>:: Stack()
{
	list = new List<VT>();
}

template <class VT>
Stack<VT>:: Stack(const Stack<VT> & S)
{
	list = new List<VT>(*(S.list));
}

template <class VT>
Stack<VT>:: ~Stack()
{
	delete list;
}

template <class VT>
int Stack<VT>:: IsEmpty()const
{
	return (list->GetFirst() == 0);
}

template <class VT>
int Stack<VT>:: IsFull()const
{
	Node<VT> *node;
	try
	{
		node = new Node<VT>;
	}
	catch(...)
	{
		return 1;
	}
	delete node;
	return 0;
}

template <class VT>
void Stack<VT>:: Push(const VT key1)
{
	if (IsFull()) throw ("Stack is full");
	list->PushStart(key1);
}

template <class VT>
VT Stack<VT>:: Pop()
{
	if (IsEmpty()) throw ("Stack is empty");
	VT tmp = list->GetFirst()->key;
	list->Remove(tmp);
	return tmp;
}

template <class VT>
VT Stack<VT>:: GetValue()
{
	if (IsEmpty()) throw ("Stack is empty");
	return list->GetFirst()->key;
}

template <class VT>
void Stack<VT>:: Print()const
{
		Stack<VT> *stack = new Stack<VT>(*this);
		while ( !(stack->IsEmpty()) )
			cout << stack->Pop() << endl;
}

template <class VT>
int Stack<VT>:: operator == (const Stack<VT> & S)const
{
	return (*list == *(S.list));
}

template <class VT>
int Stack<VT>:: operator != (const Stack<VT> & S)const
{
	return (*list != *(S.list));
}
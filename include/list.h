#include "node.h"

template <class VT>
class List
{
private:
	Node <VT> *First;
public:
	List();
	List (const List<VT> & L);
	~List();
	void Print()const;
	void PushStart (VT key1);                  //вставка в начало
	int PushBefore (VT key1, VT newkey);       //вставка перед
	int PushAfter (VT key, VT newkey);         //вставка после
	void PushEnd (VT key1);                    //вставка в конец
	Node<VT>* Find (VT key1);                  //поиск с заданным ключем
	Node<VT>* GetFirst();                      //получить начало списка
	int Remove (VT key1);                      //удаление с заданным ключем
	int operator == (const List list) const;
	int operator != (const List list) const;
};

template <class VT>
List <VT>:: List()
{
	First = 0;
}

template<class VT>
Node<VT>* List<VT>::Find(VT key1)
{
	if (First == 0) throw ("List is empty");

	Node<VT>* node = First;
	while((node != 0) && (node->key != key1))
		node = node->pNext;

	if(node == 0) throw ("This key isn't found");
	return node;
}

template <class VT>
List <VT>:: List(const List<VT> & L)
{
	First = 0;
	Node <VT> * L1 = L.First;
	while (L1 != 0)
	{
		PushEnd(L1->key);
		L1 = L1->pNext;
	}
}

template <class VT>
List <VT>:: ~List()
{	
	delete First;
}

template <class VT>
void List <VT>:: Print()const
{
	if (!First)
	{
		cout << "List is empty" <<endl;
		return;
	}
	Node <VT> *print = First;
	while (print)
	{
		cout << print->key << " -> ";
		print = print->pNext;
	}
	cout << "NULL\n";
}

template <class VT>
void List <VT>:: PushStart(VT key1)
{
	Node<VT> *p = new Node <VT>(key1);
	if (p == 0) throw ("List wasnt create");
	p->pNext = First;
	First = p;
}

template <class VT>
int List<VT>:: PushBefore (VT key1,VT newkey)
{
	Node<VT> *Curr = Find(key1);
	Node<VT> *newnode = new Node<VT>(newkey);
	if (newnode == 0) throw ("node wasn't create");
	
	Node<VT> *Prev = First;
	while(Prev->pNext != Curr)
		Prev = Prev->pNext;
	Prev->pNext = newnode;
	newnode->pNext = Curr;
	return true;
}

template <class VT>
int List<VT>:: PushAfter (VT key1, VT newkey)
{
	Node<VT> *Curr = Find(key1);
	Node<VT> *newnode = new Node<VT>(newkey);
	if (newnode == 0) throw ("node wasn't create");
	newnode->pNext = Curr->pNext;
	Curr->pNext = newnode;
	return true;
}

template <class VT>
void List<VT>:: PushEnd (VT key1)
{
	Node<VT>* curr = First;
	if(First == 0)
	{
		PushStart(key1);
		return;
	}
	while (curr->pNext)
		curr = curr->pNext;
	curr->pNext = new Node<VT>(key1);
	curr = curr->pNext;
	curr->pNext = 0;
}

template <class VT>
Node<VT>* List<VT>:: GetFirst()
{
	return First;
}

template <class VT>
int List<VT>:: Remove (VT key1)
{
	if(First == 0)
		throw ("List is empty");

    Node<VT>* Current = Find(key1);

	if (Current == First) 
	{
        First = First->pNext;
		delete Current;
        return true;
    }

    Node<VT>* Prev = First;
    while (Prev->pNext != Current)
        Prev = Prev->pNext;
    Prev->pNext = Current->pNext;
    delete Current;
	return true;
}

template <class VT>
int List<VT>:: operator == (const List list) const
{
	Node<VT> *f1 = First;
	Node<VT> *f2 = list.First;
	while ((f1 != 0) && (f2 != 0))
	{
		if (f1->key != f2->key)
			return false;
		f1 = f1->pNext;
		f2 = f2->pNext;
	}
	if (f1 != f2)
		return false;
	return true;
}

template <class VT>
int List<VT>:: operator != (const List list) const
{
	return !(*this == list);
}
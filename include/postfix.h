#include "stack.h"
#include <string>
#include <map>
typedef float RT;

template<class VT> 
class Postfix
{
private:
	Stack<VT> operators;
	Stack<VT> arguments;
	
	Stack<RT> S;
	int IsOperator(char) const;
	int IsArgument(char) const;
	//////////////////////////////
	bool GetTwoOperands (RT & op1, RT & op2);
	void Compute (char op);
public:
	Postfix();
	~Postfix();

	string PostfixForm(string);
	///////////////////////////////////
	void Calcul(void);
};

template<class VT>
Postfix<VT>:: Postfix()
{}
template<class VT>
Postfix<VT>:: ~Postfix()
{}

template<class VT>
int Postfix<VT>:: IsOperator(char value) const
{
	switch (value)
	{
		case '*': return 1;
		case '/': return 1;
		case '+': return 1;
		case '-': return 1;
		case '(': return 1;
		case ')': return 1;
		case '=': return 1;
		default:
			return 0;
	}
}

template<class VT>
int Postfix<VT>:: IsArgument(char value) const
{
	if ( (IsOperator(value)) || (value == ' ') )
		return 0;
	return 1;
}

template<class VT>
string Postfix<VT>:: PostfixForm(string str)
{
	map <char, int> priority;
	priority ['*'] = 3;
	priority ['/'] = 3;
	priority ['+'] = 2;
	priority ['-'] = 2;
	priority ['('] = 1;
	priority [')'] = 1;
	priority ['='] = 0;

	char value;
	for (unsigned int i=0; i < str.length(); i++)
	{
		value = str[i];
		if (value == ' ')
			continue;
		if (IsOperator(value))
		{
			if ( (value == ')') || (value == '(') )
			{
				if (value == ')')
				{
					while ((!operators.IsEmpty()) && (operators.GetValue() != '('))
						arguments.Push(operators.Pop());
					if (operators.IsEmpty())
						throw ("Error");
					operators.Pop();
				}
				else
				{
					operators.Push(value);
					continue;
				}
			}
			else
				if (!operators.IsEmpty())
				{
					if (priority[value] <= priority[operators.GetValue()])
					{
						while ((!operators.IsEmpty()) && (priority[value] <= priority[operators.GetValue()]))
							arguments.Push(operators.Pop());
						operators.Push(value);
					}
					else
						operators.Push(value);
				}
				else
					operators.Push(value);
		}
		else
			arguments.Push(value);
	}

	if (!operators.IsEmpty())
		while (!operators.IsEmpty())
			arguments.Push(operators.Pop());

	if (arguments.IsEmpty())
		throw ("Error");

	while (!arguments.IsEmpty())
		operators.Push(arguments.Pop());

	string str_result = "";
	while (!operators.IsEmpty())
		str_result = str_result + operators.Pop();
	
	for (unsigned int i=0; i < str_result.length(); i++)
	{
		value = str_result[i];
		if (value == '(')
			throw ("Error");
	}

	return str_result;
}

////////////////////////////////////
template<class VT>
void Postfix<VT>:: Calcul(void)
{
	char c;
	RT newop;
	while(cin>>c, c != '=')
	{
		switch(c)
		{
			case '+':
			case '-':
			case '*':
			case '/':
				Compute(c);
				break;
			default://не оператор вернуть символ
				cin.putback(c);
				cin>> newop;//читать оператор передать в стек
				S.Push(newop);
				break;
		}
	}
	if (!S.IsEmpty())
	{
		cout <<"Result: "<<( S.Pop() )<< endl; 
	}
	while (!S.IsEmpty())
		S.Pop();//очистить стек
}

template<class VT>
bool Postfix<VT>:: GetTwoOperands (RT & op1, RT & op2)
{
	if (S.IsEmpty())
	{
		cout<<"false" << endl;
		return false;
	}
	op1 = S.Pop(); //извлечь первый операнд
	if (S.IsEmpty())
	{
		cout<<"false" << endl;
		return false;
	}
	op2 = S.Pop();
	return true;
}

template<class VT>
void Postfix<VT>:: Compute (char op)
{//выполнение операции
	bool result;
	RT op1, op2;
	//извлечь два операнда и получить код завершения
	result = GetTwoOperands(op1,op2);
	//выполнить оператор поместить в стек иначе очистить стек, проверка на деление на 0
	if (result==true)
	switch (op)
	{
	case '+': S.Push(op2+op1); break;
	case '-': S.Push(op2-op1); break;
	case '*': S.Push(op2*op1); break;
	case '/':
		if (op1 == 0)
			throw ("error"); //{ cout << "NULL" << endl;}
		else
			S.Push(op2/op1);
		break;
	}
	else 
		cout << "error1" << endl;
}
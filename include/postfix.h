#include "stack.h"
#include <string>
#include <map>
typedef float ResType;

template<class VT> 
class Postfix
{
private:
	Stack<VT> operators;
	Stack<VT> arguments;

	int IsOperator(char) const;
	int IsArgument(char) const;
	bool GetTwoOperands (VT & op1, VT & op2);
public:
	Postfix();
	~Postfix();

	string PostfixForm(string);
	//ResType Calculator(string);
};

template<class VT>
bool Postfix<VT>:: GetTwoOperands (VT & op1, VT & op2)
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
	for (int i=0; i < str.length(); i++)
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
	
	for (int i=0; i < str_result.length(); i++)
	{
		value = str_result[i];
		if (value == '(')
			throw ("Error");
	}

	return str_result;
}
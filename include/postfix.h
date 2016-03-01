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
	string Enter (string str);
	bool GetTwoOperands (RT & op1, RT & op2);
	void Compute (char op);
public:
	Postfix();
	~Postfix();

	string PostfixForm(string);
	///////////////////////////////////
	RT Calcul(string str);
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
string Postfix<VT>:: Enter(string str)
{
	char ch;
	//char *s
	for (unsigned int i=0; i < str.length(); i++)
	{
		ch = str[i];
		if (IsArgument(ch))
		{
			cout << "Enter " << ch << ": ";
			cin >> str[i];
		}
	}
	return str;
}

template<class VT>
RT Postfix<VT>:: Calcul(string str)
{
	char ch;
	string s1 = Enter(str);
	RT newop;
	for (unsigned int i=0; i < s1.length(); i++)
	{
		ch = s1[i];
		if((ch!=' ')&&(ch != '='))
			switch(c)
			{
				case '+':
				case '-':
				case '*':
				case '/':
					Compute(c);
					break;
				default://�� �������� ������� ������
					cin.putback(c);
					cin>> newop;//������ �������� �������� � ����
					S.Push(newop);
					break;
			}
	}

	RT Result;
	if (!S.IsEmpty())
		Result = S.Pop();
	if (!S.IsEmpty())
		cout << "error Calcul"<< endl;
	while (!S.IsEmpty())
		S.Pop();//�������� ����
	return Result;
}

template<class VT>
bool Postfix<VT>:: GetTwoOperands (RT & op1, RT & op2)
{
	if (S.IsEmpty())
	{
		cout<<"false" << endl;
		return false;
	}
	op1 = S.Pop(); //������� ������ �������
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
{//���������� ��������
	bool result;
	RT op1, op2;
	//������� ��� �������� � �������� ��� ����������
	result = GetTwoOperands(op1,op2);
	//��������� �������� ��������� � ���� ����� �������� ����, �������� �� ������� �� 0
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
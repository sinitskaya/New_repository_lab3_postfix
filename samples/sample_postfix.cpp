#include "postfix.h"
int main()
{
	setlocale(0,"");
	string str;
	cout << "������� �������������� ���������:";
	getline(cin, str);
	Postfix<char> postfix;

	string postfix_str = postfix.PostfixForm(str);
	cout << endl << "��������� � ����������� �����: " << postfix_str << endl;

	cout << postfix.Calcul(postfix_str);
	return 0;
}
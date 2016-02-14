#include "stack.h"

int main()
{
	setlocale(0,"");
	Stack <double> *stack = new Stack <double>;
	cout << "Проверка на пустоту стека:" <<(stack->IsEmpty())<< endl;

	for (int i=0; i<5; i++)
		stack->Push(i);
	cout << "Заполение стека значениями:" << endl;
	stack->Print();

	cout << "Получить значение с верхушки, без удаления: "; 
	cout << stack->GetValue()<< endl;
	cout << "STACK:"<< endl; stack->Print();

	cout << "Снять значение с верхушки: ";
	cout << stack->Pop() << endl;
	cout << "STACK:"<< endl; stack->Print();
	return 0;
}
#include <iostream>
#include <conio.h>
#include <list>
#include "List.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

void initList(List& obj)
{
	cout << "Введите кол-во элементов списка: ";
	int NumElem;
	int addedElem;
	cin >> NumElem;
	for (int i(1); i <= NumElem; i++)
	{
		cout << "Введите значение " << i << " элемента списка: ";
		while (!(cin >> addedElem))
		{
			cin.clear();
			while (cin.get() != '/n');
			cout << "Введите значение " << i << " элемента списка";
		}
		obj.push_back(addedElem);
	}
}



void Distribution(List &obj)
{
	char c = 0;
	while (c != 8)
	{
		c = (char)_getch();

		
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	List a;
	a.fin("Bug.txt");
	std::cout << a;
	_getch();
	return 0;
}
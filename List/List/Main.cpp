#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

void initList(List& obj)
{
	cout << "������� ���-�� ��������� ������: ";
	int NumElem;
	int addedElem;
	cin >> NumElem;
	for (int i(1); i <= NumElem; i++)
	{
		cout << "������� �������� " << i << " �������� ������: ";
		while (!(cin >> addedElem))
		{
			cin.clear();
			while (cin.get() != '/n');
			cout << "������� �������� " << i << " �������� ������";
		}
		obj.AddEnd(addedElem);
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
	List c;
	initList(c);
	cout << c;
	
	_getch();
	return 0;
}
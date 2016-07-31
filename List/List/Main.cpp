#include <iostream>
#include <conio.h>
#include "List.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SLL::List a;
	for (int i(1); i <= 5; i++)
		a.Insert(i);
	std::cout << a << std::endl;
	try
	{
		A temp = a[30];
		std::cout << "key = " << temp.key << ", index = " << temp.index << std::endl;
	}
	catch (std::runtime_error a)
	{
		std::cout << a.what() << std::endl;
	}

	_getch();
	return 0;
}
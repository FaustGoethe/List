#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	List c;
	for (int i(1); i <= 5; i++)
		c.AddEnd(i + 1);

	std::cout << c;
	std::cout << c.IndexFind(2);
	_getch();
	return 0;
}
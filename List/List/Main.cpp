#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	List c;
	for (int i(0); i <= 5; i++)
		c.AddEnd(i + 1);

	std::cout << c << std::endl;
	std::cin >> c[3].key;
	_getch();
	return 0;
}
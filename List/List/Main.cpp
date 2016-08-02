#include <iostream>
#include <conio.h>
#include "List.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	List c;
	for (int i(1); i <= 5; i++)
		c.AddEnd(i);
	std::cout << c;
	c[5] = 155;
	std::cout << c;

	_getch();
	return 0;
}
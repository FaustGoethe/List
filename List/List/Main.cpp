#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	List c;
	for (int i(1); i <= 5; i++)
		c.AddEnd(i);
	
	_getch();
	return 0;
}
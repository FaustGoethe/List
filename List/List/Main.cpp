#include <iostream>
#include <conio.h>
#include "List.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SLL::List a;
	for (int i(1); i <= 5; i++)
		a.Insert(i);
	
	_getch();
	return 0;
}
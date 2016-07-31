#include <iostream>
#include <conio.h>
#include "List.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SLL::List a;
	for (int i(1); i <= 5; i++)
		a.Insert(i);
	std::ofstream fout;
	a.Encryption("Hello");
	a.Input_with_file(fout, (std::string)"text.txt", (std::string)"Hello");
	_getch();
	return 0;
}
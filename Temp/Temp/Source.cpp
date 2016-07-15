#include <iostream>
#include <conio.h>
#include "Accounts.h"

using namespace std;
using Programm::Accounts;

int main()
{
	setlocale(LC_ALL, "Russian");
	Accounts a("Кирилл",1120);
	a.Print();
	a.Print();
	
	_getch();
	return 0;
}
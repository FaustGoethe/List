#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

void general(SLL::List& obj) {
	char c;

	do {
		MENU::menu();
		c = (char)_getch();
		switch (c) {
			case '1': 
				cin >> obj;
				break;
			case '2':
				cout << obj;
				break;
			case '3':

				break;
			default:
				cout << "Bad opcode!\a";
				break;
		}
	} while (c != '7');
}

int main(int argc, char* argv[]){
	SLL::List a;
	general(a);
	return 0;
}
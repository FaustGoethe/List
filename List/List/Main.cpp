#include <iostream>
#include <conio.h>
#include "List.h"
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]){
	SLL::List a;
	for (int i(1); i <= 10; i++) {
		a.push_back(i);
	}
	
	_getch();
	return 0;
}
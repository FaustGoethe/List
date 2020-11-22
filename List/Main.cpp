#include <iostream>
#include <conio.h>
#include "List.h"


int main(int argc, char* argv[]){
	SLL::List list;

	list.push_back(12);
	try {
        std::cout << list << std::endl;
	}
	catch (const std::exception& excp) {
        std::cout << excp.what();
	}

    _getch();

	return 0;
}

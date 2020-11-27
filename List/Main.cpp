#include <iostream>
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

	return 0;
}

#pragma once

#ifndef _DEFAULT_MENU_H
#define _DEFAULT_MENU_H

#include "Menu.h"

namespace MENU {
	void menu() {
		std::cout << "1.Create list"		<< std::endl;
		std::cout << "2.Show list"			<< std::endl;
		std::cout << "3.Add/remove"			<< std::endl;
		std::cout << "4.File"				<< std::endl;
		std::cout << "5.Find the element"	<< std::endl;
		std::cout << "6.Sort list"			<< std::endl;
		std::cout << "7.Reverse list"		<< std::endl;
		std::cout << "8.Resize"				<< std::endl;
		std::cout << "9.Exit"				<< std::endl;
	}
}
#endif 
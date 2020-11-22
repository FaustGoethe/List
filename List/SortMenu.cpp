#pragma once

#ifndef _SORT_MENU_H
#define _SORT_MENU_H

#include "Menu.h"

namespace MENU {
	void SortMenu() {
		std::cout << "1.Sort value up"		<< std::endl;
		std::cout << "2.Sort value down"	<< std::endl;
		std::cout << "3.Sort index up"		<< std::endl;
		std::cout << "4.Sort index down"	<< std::endl;
		std::cout << "5.Exit"				<< std::endl;
	}
}
#endif 
#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <iostream>
namespace MENU
{
	using std::cout;
	using std::endl;
	
	// Обычное меню
	void menu(){
		cout << "1.Create list"			<< endl;
		cout << "2.Show list"			<< endl;
		cout << "3.Add/remove"			<< endl;
		cout << "4.File"				<< endl;
		cout << "5.Find the element"	<< endl;
		cout << "6.Sort list"			<< endl;
		cout << "7.Reverse list"		<< endl;
		cout << "8.Resize"				<< endl;
		cout << "9.Exit"				<< endl;
	}

	// Меню сортировки
	void SortMenu(){
		cout << "1.Sort value up"	<< endl;
		cout << "2.Sort value down" << endl;
		cout << "3.Sort index up"	<< endl;
		cout << "4.Sort index down" << endl;
		cout << "5.Exit"			<< endl;
	}

	// Меню вывода из файла
	void FinMenu()
	{
		cout << "1.Вывести список" << endl;
		cout << "2.Добавка/удаление" << endl;
		cout << "3.Найти элемент списка" << endl;
		cout << "4.Отсортировать список" << endl;
		cout << "5.Зашифровать/расшифровать список" << endl;
		cout << "6.Выйти" << endl;
	}

	// Меню fstream
	void FstreamMenu(){
		cout << "1.Into file" << endl;
		cout << "2.From file" << endl;
		cout << "3.Exit" << endl;
	}

	// Меню добавки/удаления элементов
	void ElementsMenu(){
		cout << "1.Add"					<< endl;
		cout << "2.Remove"				<< endl;
		cout << "3.Remove from index"	<< endl;
		cout << "4.Exit"				<< endl;
	}
}
#endif
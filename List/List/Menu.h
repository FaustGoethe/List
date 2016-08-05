#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <iostream>
namespace Menu
{
	using std::cout;
	using std::endl;
	
	// Обычное меню
	void menu()
	{
		cout << "1.Создать список" << endl;
		cout << "2.Вывод" << endl;
		cout << "3.Добавка/удаление" << endl;
		cout << "4.Ввод/ввывод из файла" << endl;
		cout << "5.Найти элемент списка" << endl;
		cout << "6.Отсортировать список" << endl;
		cout << "7.Зашифровать/расшифровать список" << endl;
		cout << "8.Выйти" << endl;
	}

	// Меню сортировки
	void SortMenu()
	{
		cout << "1.Отсортировать значения по увеличению" << endl;
		cout << "2.Отсортировать значения по уменьшению" << endl;
		cout << "3.Отсортировать индексы по увеличению" << endl;
		cout << "4.Отсортировать индексы по уменьшению" << endl;
		cout << "5.выйти" << endl;
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
	void FstreamMenu()
	{
		cout << "1.Ввести список в файл" << endl;
		cout << "2.Вывести список из файла" << endl;
		cout << "3.Выйти" << endl;
	}

	// Меню добавки/удаления элементов
	void ElementsMenu()
	{
		cout << "1.Добавить элемент" << endl;
		cout << "2.Удалить элемент" << endl;
		cout << "3.Удалить элемент по индексу" << endl;
		cout << "4.Выйти" << endl;
	}

}
using namespace Menu;
#endif
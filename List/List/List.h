#pragma once
#ifndef _LIST_H
#define _LIST_H
#define BAD_BEGIN "Bad begin"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace SLL
{
	typedef long double ld;

	struct status
	{
		bool Encpt_status = false;
		std::string key = "";
	};
	class List
	{	
	public:
		struct A
	{
		int key;
		size_t index;

		friend std::ostream& operator<<(std::ostream&, A&);
		inline A& operator=(size_t v)
		{
			key = v;
			return *this;
		}
	};
	    struct list
	{
		A a;
		list* next;
	};
		status status;
	private:
		list* begin;
		
		double averege_value()const; // Среднее арифметическо значение списка
		ld GeometryMean() const;
		int maximum_value()const; // максимальное значение списка
		int minimum_value()const; // минимальное значение списка
		void Indexation();
		A* Array();
	public:
		List();
		List(const List&);
		~List();

		List& Insert(const size_t); // Добавка элемента n значения в список
		List& Delete(const size_t); // Удаление элемента из списка по значению
		int IndexDelete(const int); // Удаление элемента из списка по индексу 
		List& push_back(const size_t); // Добавка элемента в конец списка
		List& push_front(const size_t); // Добавка элемента в начало списка
		size_t size() const;

		void Output_with_file(const std::string&) const;
		size_t KeyFind(const size_t); // Поиск по значению

		inline list* get_begin() // Вернуть начало
		{
			return begin;
		}

		List& set_key(std::string);

		List& KeySort();
		List& keySortMin();
		List& IndexSort();
		List& IndexSortMin();

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);

		friend void Input_with_file(List&, const std::string&);
		friend void Encryption(List&);
		
		A& operator[](const size_t);
	};
}
#endif

using namespace SLL;
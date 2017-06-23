#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace SLL
{
	typedef long double ld;

	class List
	{	
	public:

		struct content
		{
			int key;
			size_t index;

			friend std::ostream& operator<<(std::ostream&, content&);
			inline content& operator=(size_t v){
				key = v;
				return *this;
		}
		};
	    struct list
		{
			content value;
			list* next;
		};
	private:
		list* begin; // Указатель на начало
		
		void Indexation(); // Присвоение каждому элементу списка индекса
		content* Array(); // Представление списка в виде массива
	public:
		List();
		List(const List&);
		List(const int*,const int);
		~List();

		List& push(const int); // Добавка элемента n значения в список
		List& remove(const size_t); // Удаление элемента из списка по значению
		int remove_at_index(const size_t); // Удаление элемента из списка по индексу 
		List& push_back(const size_t); // Добавка элемента в конец списка
		List& push_front(const size_t); // Добавка элемента в начало списка
		size_t size() const; // Размерность списка

		double averege()const; // Среднее арифметическо значение списка
		int maximum_value()const; // максимальное значение списка
		int minimum_value()const; // минимальное значение списка

		void fout(const std::string&) const;
		size_t KeyFind(const size_t); // Поиск по значению

		inline list* _begin()const{ // Вернуть начало
			return begin;
		}
		list* _end()const;

		List& key_sort_bubble(); // Сортировка пузырьком по значению
		List& key_sort_reverse_bubble(); // Обратная сортировка пузырьком по значению
		List& index_sort_bubble(); // Сортировка пузырьком по индексу
		List& index_sort_reverse_bubble(); // Обратная сортировка пузырьком по индексу

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);

		List& fin(const std::string&);
		
		content& operator[](size_t);
		content& operator[](const size_t) const;
	};
}
#endif

using namespace SLL;
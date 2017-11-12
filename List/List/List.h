#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

namespace SLL
{
	
	class List
	{	
	public:
		struct content
		{
			int key;
			size_t index;

			friend std::ostream& operator<<(std::ostream& os, const content& value) {
				os << value.key << std::endl;
			}
			inline content& operator=(const int value){
				key = value;
				return *this;
		}
		};
	    struct list{
			content value;
			list* next;
		};
	private:
		// Указатель на начало
		list* begin; 

		// Присвоение каждому элементу списка индекса
		void Indexation();

		// Представление списка в виде массива
		content* Array(); 
	public:
		List();
		List(const List&);
		//Инициализация массивом
		List(const int*, int);
		List(int, int);
		~List();

		List& push(const int); // Добавка элемента n значения в список
		List& remove(const int); // Удаление элемента из списка по значению
		
		int remove_at_index(size_t); // Удаление элемента из списка по индексу 
		
		List& push_back(const int); // Добавка элемента в конец списка
		List& push_front(const int); // Добавка элемента в начало списка
		
		size_t size() const; // Размерность списка

		double averege()const; // Среднее арифметическо значение списка
		int max()const; // максимальное значение списка
		int min()const; // минимальное значение списка

		void fout(const std::string&) const;
		size_t find(const int); // Поиск по значению

		// Вернуть начало
		inline list* _begin() const{ 
			return begin;
		}
		// Вернуть конец
		list* _end() const {
			if (begin == NULL) {
				return NULL;
			}
			list* end = begin;

			while (end) {
				if (end->next == NULL) {
					return end;
				}
				end = end->next;
			}
		}

		// Сортировка пузырьком по значению
		void ksort() {
			if (begin == NULL) {
				return;
			}
			for (int i(1); i <= size(); i++) {
				for (int j(1); j <= i; j++) {
					if ((*this)[i].key < (*this)[j].key) {
						std::swap((*this)[i].key, (*this)[j].key);
					}
				}
			}
		}
		List& key_sort_reverse_bubble(); // Обратная сортировка пузырьком по значению
		List& index_sort_bubble(); // Сортировка пузырьком по индексу
		List& index_sort_reverse_bubble(); // Обратная сортировка пузырьком по индексу

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);

		List& fin(const std::string&);
		
		content& operator[](size_t);
		content& operator[](size_t) const;
	};
}
#endif

using namespace SLL;
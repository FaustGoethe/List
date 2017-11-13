#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <fstream>
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
				return os;
			}

			content& operator=(const int value){
				key = value;
				return *this;
		}
		};
	    struct list{
			content value;
			list* next;
		};
	private:
		list* begin; 

		void Indexation() {
			if (begin == NULL) {
				return;
			}
			list* temp = begin;

			for (size_t i(1); i <= size(); i++) {
				temp->value.index = i;
				temp = temp->next;
			}
		}
	public:
		List() {
			begin = NULL;
		}
		List(const List& cp) {
			begin = cp.begin;
		}
		List(const int* arr, int size) {
			begin = NULL;

			for (int i(0); i < size; i++) {
				push_back(arr[i]);
			}
		}
		//List(int, int);
		~List() {
			if (begin == NULL) {
				return;
			}

			list* deleting = begin;
			list* temp;

			while (deleting->next) {
				temp = deleting;
				deleting = deleting->next;
				delete temp;
			}

			begin = NULL;
		}

		void push(int push_value) {
			list* ins = new list; // Добавляемый элемент
			ins->value.key = push_value;
			ins->next = NULL;

			list* t = begin;
			if (begin == NULL) {
				ins->value.index = 1;
				begin = ins;
			}

			if (ins->value.key <= t->value.key) {
				ins->next = t;
				begin = ins;
				Indexation();
			}

			list* t1 = t->next;
			while (t != NULL) {
				if (t->next == NULL) {
					t->next = ins;
					Indexation();
				}

				if (ins->value.key >= t->value.key && ins->value.key <= t1->value.key) {
					t->next = ins;
					ins->next = t1;
					Indexation();
				}

				t = t->next;
				t1 = t->next;
			}
		}
		void remove(int remove_value) {
			if (begin == NULL) {
				throw std::runtime_error("The element can't be remove, because begin == null\a");
			}

			list* t = begin;

			if (t->value.key == remove_value) {
				begin = t->next;
				delete t;
				Indexation();
				return;
			}

			list*  t1 = t->next;
			while (t1 != NULL) {
				if (t1->value.key == remove_value) {
					t->next = t1->next;
					delete t1;
					Indexation();
					return;
				}
				t = t1;
				t1 = t1->next;
			}
			throw std::runtime_error("Element not found");
		}
		
		void remove_at_index(size_t remove_index) {
			if (begin == NULL) {
				throw std::runtime_error("The element can't be remove, because begin == null\a");
			}
			if (remove_index <= 0 || remove_index > size()) {
				throw std::runtime_error("Bad index\a");
			}
			
			list* t = begin;
			list* t1 = begin->next;
			
			if (t->value.index == remove_index) {
				begin = t->next;
				delete t;
				Indexation();
			}

			while (t1) {
				if (t1->value.index == remove_index) {
					t->next = t1->next;
					delete t1;
					Indexation();
					return;
				}
				t = t1;
				t1 = t1->next;
			}
		}

		void push_back(int push_value) {
			list* ins = new list;
			ins->value.key = push_value;
			ins->next = NULL;

			if (begin == NULL) {
				begin = ins;
				Indexation();
				return;
			}

			list* t = begin;
			while (t) {
				if (t->next == NULL) {
					t->next = ins;
					ins->next = NULL;
					Indexation();
					return;
				}
				t = t->next;
			}
			Indexation();
		}
		void push_front(int push_value) {
			list* ins = new list;

			ins->value.key = push_value;
			ins->next = begin;

			begin = ins;
			Indexation();
		}
		
		size_t size() const {
			if (begin == NULL) {
				return 0;
			}

			list* temp = begin;
			size_t result = 0;

			while (temp){
				result++;
				temp = temp->next;
			}
			return result;
		}

		double averege() const {
			if (begin == NULL) {
				return 0;
			}

			list* temp = begin;

			auto i = 0;

			while (temp != NULL) {
				i += temp->value.key;
				temp = temp->next;
			}

			return i / size();
		}
		int max() const {
			if (begin == NULL) {
				return 0;
			}

			list* temp = begin;
			int result = 0;

			while (temp != NULL) {
				if (temp->value.key > result) {
					result = temp->value.key;
				}
				temp = temp->next;
			}
			return result;
		}
		int min() const {
			if (begin == NULL) {
				return 0;
			}

			list* temp = begin;
			int result = LONG_MAX;

			while (temp){
				if (temp->value.key < result) {
					result = temp->value.key;
				}
				temp = temp->next;
			}

			return result;
		}

		size_t find(int key) {
			for (size_t i(1); i <= size(); i++) {
				if ((*this)[i].key == key) {
					return (*this)[i].index;
				}
			}
			return 0;
		}

		list* _begin() const{ 
			return begin;
		}
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
		void rksort() {
			if (begin == NULL) {
				return;
			}
			for (int i(1); i <= size(); i++) {
				for (int j(1); j <= i; j++) {
					if ((*this)[i].key > (*this)[j].key) {
						std::swap((*this)[i].key, (*this)[j].key);
					}
				}
			}
		}

		void isort() {
			if (begin == NULL) {
				return;
			}
			for (int i(1); i <= size(); i++) {
				for (int j(1); j <= i; j++) {
					if ((*this)[i].index < (*this)[j].index) {
						std::swap((*this)[i], (*this)[j]);
					}
				}
			}
		}
		void irsort() {
			if (begin == NULL) {
				return;
			}
			for (int i(1); i <= size(); i++) {
				for (int j(1); j <= i; j++) {
					if ((*this)[i].index > (*this)[j].index) {
						std::swap((*this)[i], (*this)[j]);
					}
				}
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const List& value) {
			SLL::List::list* print = value.begin;

			while (print){
				os << print->value.key << " -> ";
				print = print->next;
			}
			os << "NULL" << std::endl;

			print = value.begin;

			while (print){
				os << print->value.index << " -> ";
				print = print->next;
			}
			os << "NULL" << std::endl;
			os << std::endl;

			os.setf(std::ios_base::fixed, std::ios_base::floatfield);
			os.precision(2);

			os << "Average: "	<< value.averege() << std::endl;
			os << "Max: "		<< value.max() << std::endl;
			os << "Min: "		<< value.min() << std::endl;

			os << std::endl;
			return os;
		}
		friend std::istream& operator>>(std::istream& is, List& value) {
			size_t elemNum;

			std::cout << "Enter number elements: ";
			is >> elemNum;
		
			int add;
			for (int i(0); i < elemNum; i++) {
				is >> add;
				value.push_back(add);
			}
			return is;
		}

		friend std::ofstream& operator<<(std::ofstream& fout, const List& value) {
			if (value.begin == NULL) {
				throw std::runtime_error("This list can't be output, because begin == null\a");
			}
			if (!fout.is_open()) {
				throw std::invalid_argument("File is not opened");
			}

			list* print = value.begin;

			for (size_t i(0); i < value.size() - 1; i++) {
				fout << print->value.key << std::endl;
				print = print->next;
			}
			fout << print->value.key;

			return fout;
		}
		friend std::ifstream& operator>>(std::ifstream& fin, List& value) {
			if (!fin.is_open()) {
				throw std::invalid_argument("The file is not opened\a");
			}
			int addValue;

			if (fin) {
				while (!fin.eof()) {
					fin >> addValue;
					value.push_back(addValue);
				}
			}

			value.Indexation();
			return fin;
		}
		
		content& operator[](size_t index) {
			if (index > size() || index <= 0)
				throw std::runtime_error("Error memory access\a");

			int temp = 1;
			list* ret = begin; // Возвращаемый экземпляр структуры

			for (;;) {
				if (temp == index) {
					return ret->value;
				}
				temp++;
				ret = ret->next;
			}
		}
		content& operator[](size_t index) const {
			if (index > size() || index <= 0)
				throw std::runtime_error("Error memory access\a");

			int temp = 1;
			list* ret = begin; // Возвращаемый экземпляр структуры

			for (;;)
			{
				if (temp == index)
					return ret->value;

				temp++;
				ret = ret->next;
			}
		}
	};
}
#endif
using namespace SLL;
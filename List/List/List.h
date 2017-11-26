#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <exception>
#include <iostream>
#include <fstream>
#include <string>

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

		void Indexation() noexcept {
			if (begin == NULL) {
				return;
			}
			list* temp = begin;

			for (size_t i(1); i <= size(); i++) {
				temp->value.index = i;
				temp = temp->next;
			}
		}

		int recevingExistCodes(int x) const noexcept {
			x += 256;
			while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
				if (x < 48) {
					x += 24;
				}
				else {
					x -= 47;
				}
			}
			return x;
		}
		size_t getControlSum(const std::string& str) const noexcept {
			size_t sault = 0;

			for (size_t strlen(0); strlen < str.size(); strlen += 2) {
				sault += int(str[strlen]);
			}
			return sault;
		}

		list* _end() noexcept {
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
	public:
		List() noexcept {
			begin = NULL;
		}
		List(const List& cp) noexcept {
			if (begin != NULL) {
				clear();
			}
			
			*begin = *cp.begin;
		}
		List(const int* arr, int size) noexcept {
			begin = NULL;

			for (int i(0); i < size; i++) {
				push_back(arr[i]);
			}
		}
		List(size_t size, int value) noexcept{
			for (size_t i(0); i < size; i++) {
				push_back(value);
			}
		}
		~List() noexcept {
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

		List& operator()(const List& cp) noexcept {
			clear();
			*begin = *cp.begin;
		}

		List& operator=(const List& cp) noexcept {
			clear();
			begin = cp.begin;
			return *this;
		}

		void push(int push_value) noexcept {
			list* ins = new list; // Добавляемый элемент
			ins->value.key = push_value;
			ins->next = NULL;

			list* t = begin;
			if (begin == NULL) {
				ins->value.index = 1;
				begin = ins;
				return;
			}

			if (ins->value.key <= t->value.key) {
				ins->next = t;
				begin = ins;
				Indexation();
				return;
			}

			list* t1 = t->next;
			while (t != NULL) {
				if (t->next == NULL) {
					t->next = ins;
					Indexation();
					return;
				}

				if (ins->value.key >= t->value.key && ins->value.key <= t1->value.key) {
					t->next = ins;
					ins->next = t1;
					Indexation();
					return;
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

		void push_back(int push_value) noexcept {
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
		void push_front(int push_value) noexcept {
			list* ins = new list;

			ins->value.key = push_value;
			ins->next = begin;

			begin = ins;
			Indexation();
		}
		
		void pop_back() noexcept {
			if (begin == NULL) {
				return;
			}
			list* t = begin;
			list* t1 = t->next;

			while (t) {
				if (t1->next == NULL) {
					delete t1;
					t->next = NULL;
					return;
				}
				t = t->next;
				t1 = t1->next;
			}
		}
		void pop_front() noexcept {
			if (begin == NULL) {
				return;
			}
			list* pop = begin;
			begin = begin->next;
			delete pop;
			Indexation();
		}

		size_t size() const noexcept {
			if (begin == NULL) {
				return 0;
			}

			list* counter = begin;
			size_t result = 0;

			while (counter){
				result++;
				counter = counter->next;
			}
			return result;
		}
		bool empty() const noexcept {
			return (begin == NULL);
		}

		double averege() const noexcept {
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
		int max() const noexcept {
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
		int min() const noexcept {
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

		int count(int key) {
			int count = 0;
			for (size_t i(1); i <= size(); i++) {
				if ((*this)[i].key == key) {
					count++;
				}
			}
			return (count == 0) ? -1 : count;
		}

		list* _begin() const noexcept {
			return begin;
		}
		list* _end()   const noexcept {
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
			for (size_t i(1); i <= size(); i++) {
				for (size_t j(1); j <= i; j++) {
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
			for (size_t i(1); i <= size(); i++) {
				for (size_t j(1); j <= i; j++) {
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
			for (size_t i(1); i <= size(); i++) {
				for (size_t j(1); j <= i; j++) {
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
			for (size_t i(1); i <= size(); i++) {
				for (size_t j(1); j <= i; j++) {
					if ((*this)[i].index > (*this)[j].index) {
						std::swap((*this)[i], (*this)[j]);
					}
				}
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const List& value) noexcept {
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

			os << "Average: "	<< value.averege()	 << std::endl;
			os << "Max: "		<< value.max()		 << std::endl;
			os << "Min: "		<< value.min()		 << std::endl;
			os << "Hash: "		<< value.getHash(32) << std::endl;

			os << std::endl;
			return os;
		}
		friend std::istream& operator>>(std::istream& is, List& value) noexcept {
			value.clear();

			size_t elemNum;

			std::cout << "Enter number elements: ";
			is >> elemNum;
		
			int add = 0;
			for (size_t i(0); i < elemNum; i++) {
				while (!(is >> add)) {
					is.clear();
					while (is.get() != '\n');
				}
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

			list* fprint = value.begin;

			for (size_t i(0); i < value.size() - 1; i++) {
				fout << fprint->value.key << std::endl;
				fprint = fprint->next;
			}
			fout << fprint->value.key;

			return fout;
		}
		friend std::ifstream& operator>>(std::ifstream& fin, List& value) {
			if (!fin.is_open()) {
				throw std::invalid_argument("The file is not opened\a");
			}
			value.clear();

			int addValue = 0;
			if (fin) {
				while (!fin.eof()) {
					fin >> addValue;
					value.push_back(addValue);
				}
			}
			
			return fin;
		}
		
		content& operator[](size_t index) {
			if (index > size() || index <= 0)
				throw std::runtime_error("Error memory access\a");

			size_t size = 1;
			list* ret = begin; // Возвращаемый экземпляр структуры

			for (;;) {
				if (size == index) {
					return ret->value;
				}
				size++;
				ret = ret->next;
			}
		}
		content& operator[](size_t index) const {
			if (index > size() || index <= 0)
				throw std::runtime_error("Error memory access\a");

			size_t size = 1;
			list* ret = begin; // Возвращаемый экземпляр структуры

			for (;;){
				if (size == index) {
					return ret->value;
				}
				size++;
				ret = ret->next;
			}
		}

		std::string getHash(size_t hashLength) const {
			if (begin == NULL) {
				return "0";
			}
			
			if (hashLength < 3) {
				throw std::invalid_argument("Hash lengt can't be < 3!\a");
			}
			std::string userString = "";
			list* adder = begin;

			while (adder) {
				userString += std::to_string(adder->value.key);
				adder = adder->next;
			}

			std::string hash;

			size_t minlen = 2;
			size_t realMinLen = 0;

			size_t oroginalSault = getControlSum(userString);
			size_t oroginalLengtStr = userString.size();

			while (minlen <= hashLength)		{ realMinLen = (minlen *= 2); }
			while (minlen < oroginalLengtStr)	{ minlen *= 2; }

			if (minlen - oroginalLengtStr < minlen) { minlen *= 2; }

			int addCount = minlen - oroginalLengtStr;

			for (int i(0); i < addCount; i++) {
				userString += recevingExistCodes(userString[i] + userString[i + 1]);
			}

			int maxSault = getControlSum(userString);
			int maxLengtStr = userString.size();

			while (userString.size() != realMinLen) {
				for (int i(0), center(userString.size() / 2); i < center; i++) {
					hash += recevingExistCodes(userString[center - i] + userString[center + i]);
				}
				userString = hash;
				hash.clear();
			}
			size_t rem = realMinLen - hashLength;

			for (size_t i(0), CountCompress(realMinLen / rem); hash.size() < (hashLength - 4); i++) {
				if (i % CountCompress == 0) {
					hash += recevingExistCodes(userString[i] + userString[++i]);
				}
				else {
					hash += userString[i];
				}
			}
			hash += recevingExistCodes(oroginalSault);
			hash += recevingExistCodes(oroginalLengtStr);

			hash += recevingExistCodes(maxSault);
			hash += recevingExistCodes(maxLengtStr);
			return hash;
		}

		void clear() noexcept {
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

		void resize(size_t newSize) noexcept {
			list* parser = begin;
			while (parser) {
				if (newSize > size()) {
					push_back(0);
				}

				else if (newSize < size()) {
					pop_back();
				}
				parser = parser->next;
			}
		}
		void resize(size_t newSize, int value) noexcept {
			list* parser = begin;
			while (parser) {
				if (newSize > size()) {
					push_back(value);
				}

				else if (newSize < size()) {
					pop_back();
				}
				parser = parser->next;
			}
		}

		void reverse() {
			if (begin == NULL) {
				return;
			}

			for (int i(1), j(size()); i <= j; i++, j--) {
				std::swap((*this)[i], (*this)[j]);
			}
		}
		
		//get type
		//find
	};
}
#endif
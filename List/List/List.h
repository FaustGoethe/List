#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <exception>
#include <iostream>
#include <fstream>
#include <string>

namespace SLL{
	class List
	{	
	public:
		struct content{
			int key;
			size_t index;

			friend std::ostream& operator<<(std::ostream&, const content&) noexcept;

			content& operator=(int);
		};
	    struct list{
			content value;
			list* next;

			friend std::ostream& operator<<(std::ostream&, const list&) noexcept;
		};
	private:
		list* begin; 

		void Indexation() noexcept;
		
		int recevingExistCodes(int)					const noexcept;
		size_t getControlSum(const std::string&)	const noexcept;

		list* _end() noexcept;
	public:
		List()					noexcept;
		List(const List&)		noexcept;
		List(const int*, int)	noexcept;
		List(size_t, int)		noexcept;
		~List()					noexcept;

		List& operator()(const List&) noexcept;
		List& operator= (const List&) noexcept;

		void push	(int) noexcept;
		void remove	(int);
		
		void remove_at_index(size_t);

		void push_back	(int) noexcept;
		void push_front	(int) noexcept;
		
		void pop_back  () noexcept;
		void pop_front () noexcept;

		size_t	size()	const noexcept;
		bool	empty()	const noexcept;

		double averege()	const noexcept;
		int max()			const noexcept;
		int min()			const noexcept;

		int count(int key) const {
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
			list* print = value.begin;

			while (print){
				os << print->value << " -> ";
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
				throw std::runtime_error("This list can't be output, because begin == null;\a" + 
					std::string("Code file: ") +
					__FILE__ +
					", line: " +
					std::to_string(__LINE__) +
					", func: " +
					__func__);
			}
			if (!fout.is_open()) {
				throw std::invalid_argument("File is not opened;\n" + 
					std::string("Code file: ") +
					__FILE__ +
					", line: " +
					std::to_string(__LINE__) +
					", func: " +
					__func__);
			}

			list* fprint = value.begin;

			for (size_t i(0); i < value.size() - 1; i++) {
				fout << fprint->value << std::endl;
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
				throw std::runtime_error(("Error memory access\a"));

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
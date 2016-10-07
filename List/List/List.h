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
		
		ld Averege()const;
		ld GeometryMean() const;
		int Maximum()const;
		int Minimum()const;
		void Indexation();
		A* Array();
	public:
		List();
		List(const List&);
		~List();

		List& Insert(const size_t);
		List& Delete(const size_t);
		int IndexDelete(const int);
		List& AddEnd(const size_t);
		List& AddBegin(const size_t);
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
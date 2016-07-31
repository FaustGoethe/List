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
	struct A
	{
		int key;
		size_t index;
	};
	struct list
	{
		A a;
		list* next;
	};

	class List
	{	
	private:
		list* begin;
		bool Encryption_status = false;
	
		ld Averege()const;
		ld GeometryMean() const;
		int Maximum()const;
		int Minimum()const;
		void Indexation() const;

		class Element_not_found {};
		class Begin_is_zero {};
	public:
		List();
		List(const List&);
		~List();

		void Insert(const size_t);
		void Delete(const size_t);
		int IndexDelete(const int);
		size_t size() const;
		void Encryption(const std::string&);
		void Input_with_file(std::ofstream&, std::string&, std::string&);

		inline list* get_begin() const
		{
			return begin;
		}

		friend std::ostream& operator<<(std::ostream&, List&);
		A& operator[](const size_t);
	};
}
#endif

using namespace SLL;
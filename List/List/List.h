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

		friend std::ostream& operator<<(std::ostream&,const A&);
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
	
	class List
	{	
	private:
		struct Encryption
		{
			bool Encryption_status = false;
			std::string key;

		};
		list* begin;
		Encryption status;

		ld Averege()const;
		ld GeometryMean() const;
		int Maximum()const;
		int Minimum()const;
		void Indexation();
	public:
		class Element_not_found {};
		class Begin_is_zero {};
	public:
		List();
		List(const List&);
		~List();

		void Insert(const size_t);
		void Delete(const size_t);
		int IndexDelete(const int);
		List& AddEnd(size_t);
		List& AddBegin(size_t);
		size_t size() const;
		List& Encryption();
		void Output_with_file(const std::string&) const;
		size_t KeyFind(size_t);
	
		friend void Input_with_file(List&, const std::string&);

		inline list* _begin() const
		{
			return begin;
		}
		list* _end() const;

		friend std::ostream& operator<<(std::ostream&, const List&);
		friend std::istream& operator>>(std::istream&, List&);
		A& operator[](const size_t);
	};
}
#endif

using namespace SLL;
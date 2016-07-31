#pragma once
#ifndef _LIST_H
#define _LIST_H
#include <iostream>
#include <string>

namespace SLL
{
	typedef long double ld;
	class List
	{	
	private:
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
	private:
		list* begin;
		bool Encryption_status = false;
	
		ld Averege()const;
		ld GeometryMean() const;
		int Maximum()const;
		int Minimum()const;
		void Indexation() const;

		class Element_not_found 
		{
		public:
			Element_not_found(){}	
		};
	public:
		List();
		List(const List&);
		~List();

		void Insert(const size_t);
		void Delete(const size_t);
		int IndexDelete(const int);
		size_t size() const;
		void Encryption(const std::string&);
		inline list* get_begin() const
		{
			return begin;
		}

		friend std::ostream& operator<<(std::ostream&, List&);
	};
}
#endif

using namespace SLL;
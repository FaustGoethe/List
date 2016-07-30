#pragma once
#ifndef _LIST_H
#define _LIST_H
#include <iostream>

namespace SinglyLinkedList
{
	typedef long double ld;
	class List1
	{
	public:
		struct A
		{
			int key;
			size_t index;
		};
	private:
		struct list1
		{
			A a;
			list1* next;
		};
		list1* begin;
	
		ld Averege() const;
		ld GeometryMean() const;
		int Maximum()const;
		int Minimum()const;
		void Indexation();
	public:
		List1();
		List1(size_t);
		~List1();

		void Insert(const A&);
		void Delete(const A&);
		size_t size() const;

		friend std::ostream& operator<<(std::ostream&,List1&);
	};
}
#endif
namespace list = SinglyLinkedList;
using namespace list;
#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <exception>
#include <iostream>
#include <fstream>
#include <string>


namespace SLL{
    struct content{
        int value;
        size_t index;

		friend std::ostream& operator<<(std::ostream&, const content&) noexcept;
		content& operator=(int);
    }
    

    struct list{
        content value;
        list* next; // the pointer links to the next element or NULL

		friend std::ostream& operator<<(std::ostream&, const list&) noexcept;
    }


	class List{	
	public:
		List()					noexcept; // base constructor
		List(const List&)		noexcept; // copying constructor
		List(const int*, int)	noexcept; // from array
		List(size_t, int)		noexcept; // some values
		~List()					noexcept;

		List& operator()(const List&) noexcept;
		List& operator= (const List&) noexcept;

		void push(int) noexcept;
		void remove(int); // remove by value
		void pop(size_t); // remove by index

		void push_back(int)  noexcept;
		void push_front(int) noexcept;
		
		void pop_back()  noexcept;
		void pop_front() noexcept;

		size_t size()  const noexcept;
		bool   empty() const noexcept;

		double averege() const noexcept;
		int max()		 const noexcept;
		int min()		 const noexcept;

		int count(int) const;

		list* _begin() const noexcept;
		list* _end()   const noexcept;

		void vsort(bool); // sort by values, key of reverse sort
		void isort(bool); // sort by indexes, key of reverse sort

		friend std::ostream& operator<<(std::ostream&, const List&) noexcept;
		friend std::ofstream& operator<<(std::ofstream&, const List&);
		
		content& operator[](size_t);
		content& operator[](size_t) const;

		void clear() noexcept;

		void resize(size_t, int)	noexcept;
		void resize(size_t)			noexcept;

		void reverse();
	private:
		list* begin;

		void Indexation() noexcept;

		list* _end() noexcept;
		//get type
		//find
	};
}
#endif

#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <exception>
#include <iostream>
#include <fstream>
#include <string>


namespace SLL{
    struct content{
        int32_t value;
        uint32_t index;

		friend std::ostream& operator<<(std::ostream&, const content&) noexcept;
		content& operator=(int32_t) noexcept;
    }
    

    struct list{
        content value;
        list* next; // the pointer links to the next element or NULL

		friend std::ostream& operator<<(std::ostream&, const list&) noexcept;
    }


	class List{	
	public:
		List() noexcept; // base constructor
		List(const List&) noexcept; // copying constructor
		List(const int32_t*, uint32_t) noexcept; // from array
		List(uint32_t, int32_t)	noexcept; // some values
		~List()	noexcept;

		List& operator()(const List&) noexcept;
		List& operator= (const List&) noexcept;

		void push(int32_t) noexcept;
		void remove(int32_t); // remove by value
		void pop(uint32_t); // remove by index

		void push_back(int32_t)  noexcept;
		void push_front(int32_t) noexcept;
		
		void pop_back()  noexcept;
		void pop_front() noexcept;

		uint32_t size()  const noexcept;
		bool   empty() const noexcept;

		double averege() const noexcept;
		int32_t max()		 const noexcept;
		int32_t min()		 const noexcept;

		int64_t count(int32_t) const;

		list* _begin() const noexcept;
		list* _end()   const noexcept;

		void vsort(bool); // sort by values, key of reverse sort
		void isort(bool); // sort by indexes, key of reverse sort

		friend std::ostream& operator<<(std::ostream&, const List&) noexcept;
		friend std::ofstream& operator<<(std::ofstream&, const List&);
		
		content& operator[](uint32_t);
		content& operator[](uint32_t) const;

		void clear() noexcept;

		void resize(uint32_t, int32_t)	noexcept;
		void resize(uint32_t)			noexcept;

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

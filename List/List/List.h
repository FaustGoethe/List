#pragma once
#ifndef _LIST_H
#define _LIST_H

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using std::string;

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
		struct iterator {
		private:
		public:
			std::shared_ptr<list*> _myiter;
			iterator() {
				(*_myiter) = NULL;
			}
			iterator& operator=(const iterator& _newiter) {
				_myiter = _newiter._myiter;
				return *this;
			}
			iterator& operator=(list* _lst) {
				*_myiter = _lst;
				return *this;
			}
			iterator(list* _lst) {
				*_myiter = _lst;
			}
			void operator++() {
				if (_myiter == NULL) {
					throw std::runtime_error(("Incrementing null"));
				}
				
				
			}
			void operator--() {

			}
		};
		iterator bgn() {
			return begin;
		}
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

		int count(int) const;

		list* _begin() const noexcept;
		list* _end()   const noexcept;

		void ksort(); // По ключам
		void isort(); // По ключам в обратном порядке

		void rksort(); // По индексам
		void irsort(); // По индексам в обратном порядке

		friend std::ostream& operator<<(std::ostream&, const List&) noexcept;
		friend std::istream& operator>>(std::istream&,		 List&) noexcept;

		friend std::ofstream& operator<<(std::ofstream&, const  List&);
		friend std::ifstream& operator>>(std::ifstream&,		List&);
		
		content& operator[](size_t);
		content& operator[](size_t) const;

		string getHash(size_t) const;

		void clear() noexcept;

		void resize(size_t)			noexcept;
		void resize(size_t, int)	noexcept;

		void reverse();

	private:
		list* begin; 

		void Indexation() noexcept;
		
		int	recevingExistCodes(int)	const noexcept;
		size_t getControlSum(const string&) const noexcept;

		list* _end() noexcept;
		//get type
		//find
	};
}
#endif
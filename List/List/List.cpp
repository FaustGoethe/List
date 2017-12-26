#pragma once
#ifndef _LIST_CPP
#define _LIST_CPP

#include "List.h"
#include "GetFilename.h"

#define EXCEPT(X) (X) + ((std::string("\a\nFile: ") + GetFilename(__FILE__) + "\nFunc: " + __func__ + "()" + "\nLine: " + std::to_string(__LINE__)) 

namespace SLL {
	std::ostream& operator<<(std::ostream& os, const List::content& _val) noexcept{
		return os << _val.key;
	}
	std::ostream& operator<<(std::ostream& os, const List::list&	_val) noexcept {
		return os << _val.value;
	}
	List::content& List::content::operator=(int _val) {
		key = _val;
		return *this;
	}


	void List::Indexation() noexcept {
		if (begin == NULL) {
			return;
		}
		list* temp = begin;

		for (size_t i(1); i <= size(); i++) {
			temp->value.index = i;
			temp = temp->next;
		}
	}

	int List::recevingExistCodes(int x) const noexcept {
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
	size_t List::getControlSum	(const std::string& str) const noexcept {
		size_t sault = 0;

		for (size_t strlen(0); strlen < str.size(); strlen += 2) {
			sault += int(str[strlen]);
		}
		return sault;
	}

	List::list* List::_end() noexcept {
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


	List::List() noexcept {
		begin = NULL;
	}
	List::List(const List& cp) noexcept {
		if (begin != NULL) {
			clear();
		}

		*begin = *cp.begin;
	}
	List::List(const int* arr, int size) noexcept {
		begin = NULL;

		for (int i(0); i < size; i++) {
			push_back(arr[i]);
		}
	}
	List::List(size_t size, int value) noexcept {
		begin = NULL;

		for (size_t i(0); i < size; i++) {
			push_back(value);
		}
	}
	List::~List() noexcept {
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

	List& List::operator()	(const List& cp) noexcept {
		clear();
		*begin = *cp.begin;
		return *this;
	}
	List& List::operator=	(const List& cp) noexcept {
		clear();
		begin = cp.begin;
		return *this;
	}

	void List::push		(int _value) noexcept {
		list* ins = new list; // Добавляемый элемент
		ins->value.key = _value;
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
	void List::remove	(int _value) {
		if (begin == NULL) {
			throw std::runtime_error(EXCEPT("Begin is null")));
		}

		list* t = begin;

		if (t->value.key == _value) {
			begin = t->next;
			delete t;
			Indexation();
			return;
		}

		list*  t1 = t->next;
		while (t1 != NULL) {
			if (t1->value.key == _value) {
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

	void List::remove_at_index(size_t remove_index) {
		if (begin == NULL) {
			throw std::runtime_error(EXCEPT("Bad begin!")));
		}
		if (remove_index <= 0 || remove_index > size()) {
			throw std::runtime_error(EXCEPT("Bad index")));
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

	void List::push_back	(int push_value) noexcept {
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
	void List::push_front	(int push_value) noexcept {
		list* ins = new list;

		ins->value.key = push_value;
		ins->next = begin;

		begin = ins;
		Indexation();
	}

	void List::pop_back() noexcept {
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
	void List::pop_front() noexcept {
		if (begin == NULL) {
			return;
		}
		list* pop = begin;
		begin = begin->next;
		delete pop;
		Indexation();
	}

	size_t	List::size()	const noexcept {
		if (begin == NULL) {
			return 0;
		}

		list* counter = begin;
		size_t result = 0;

		while (counter) {
			result++;
			counter = counter->next;
		}
		return result;
	}
	bool	List::empty()	const noexcept {
		return (begin == NULL);
	}

	double	List::averege() const noexcept {
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
	int		List::max()		const noexcept {
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
	int		List::min()		const noexcept {
		if (begin == NULL) {
			return 0;
		}

		list* temp = begin;
		int result = LONG_MAX;

		while (temp) {
			if (temp->value.key < result) {
				result = temp->value.key;
			}
			temp = temp->next;
		}

		return result;
	}
}
#endif // !_LIST_CPP
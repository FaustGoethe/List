#pragma once
#ifndef _LIST_CPP
#define _LIST_CPP

#include "List.h"

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
	size_t List::getControlSum(const std::string& str) const noexcept {
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
}
#endif // !_LIST_CPP
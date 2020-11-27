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
		list* iter = begin;
        uint32_t index = 0;

        while(iter){
            iter->value.index = index;
            ++index;
        }
	}

	void List::push_back(int32_t value) noexcept {
		list* inserter = new list;

		inserter->value.value = value;
		inserter->next = NULL;

		if (begin == NULL) {
			begin = inserter;
            begin->value.index = 0;
			return;
		}

		list* iter = begin;
		while (iter) {
			if (iter->next == NULL) {
				iter->next = inserter;
				inserter->next = NULL;
				inserter->value.index = iter->value.index + 1;
				return;
			}
			iter = iter->next;
		}
	}
	void List::push_front (int32_t value) noexcept {
		list* inserter = new list;

		inserter->value.value = value;
		inserter->next = begin;

		begin = inserter;
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

	uint32_t List::size()	const noexcept {
		if (begin == NULL) {
			return 0;
		}

		list* counter = begin;
		uint32_t result = 0;

		while (counter) {
			++result;
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
	int32_t 		List::max()		const noexcept {
		if (begin == NULL) {
			return 0;
		}

		list* temp = begin;
		int32_t result = 0;

		while (temp != NULL) {
			if (temp->value.key > result) {
				result = temp->value.key;
			}
			temp = temp->next;
		}
		return result;
	}
	int32_t List::min()	const noexcept {
		if (begin == NULL) {
			return 0;
		}

		list* temp = begin;
		int32_t result = NULL;

		while (temp) {
			if (result == NULL || temp->value.key < result) {
				result = temp->value.key;
			}
			temp = temp->next;
		}

		return result;
	}

	int64_t List::count(int32_t key) const {
		uint32_t count = 0;
        list* iter = begin;
        while (iter) {
            if (iter->value == key){
                ++count;
            }
            iter = iter->next;
        }

		return (count == 0) ? -1 : count;
	}

	List::list* List::_begin() const noexcept {
		return begin;
	}
	List::list* List::_end()   const noexcept {
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
		return end;
	}

	void List::ksort(bool reverse) {
		if (begin == NULL) {
			return;
		}
		// TODO: define lambda depending on reverse
		for (uint32_t i(1); i <= size(); i++) {
			for (uint32_t j(1); j <= i; j++) {
				if ((*this)[i].key < (*this)[j].key) {
					std::swap((*this)[i].key, (*this)[j].key);
				}
			}
		}
	}

	void List::isort(bool reverse) {
		if (begin == NULL) {
			return;
		}
		for (uint32_t i(1); i <= size(); i++) {
			for (uint32_t j(1); j <= i; j++) {
				if ((*this)[i].index < (*this)[j].index) {
					std::swap((*this)[i], (*this)[j]);
				}
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, const List& value) noexcept {
		List::list* print = value.begin;

		while (print) {
			os << print->value << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;

		print = value.begin;

		while (print) {
			os << print->value.index << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;
		os << std::endl;

		os.setf(std::ios_base::fixed, std::ios_base::floatfield);
		os.precision(2);

		os << "Average: " << value.averege() << std::endl;
		os << "Max: " << value.max() << std::endl;
		os << "Min: " << value.min() << std::endl;

		os << std::endl;
		return os;
	}

	std::ofstream& operator<<(std::ofstream& fout, const List& value) {
		if (value.begin == NULL) {
			throw std::runtime_error("Bad begin");
		}
		if (!fout.is_open()) {
			throw std::invalid_argument("Bad filename");
		}

		List::list* fprint = value.begin;

		for (uint32_t i(0); i < value.size() - 1; i++) {
			fout << fprint->value << std::endl;
			fprint = fprint->next;
		}
		fout << fprint->value.key;

		return fout;
	}

	List::content& List::operator[](const uint32_t& index) {
		if (index > size() || index <= 0)
			throw std::out_of_range("Error memory access\a");

		list* ret = begin; // Возвращаемый экземпляр структуры

        while (ret){
            if (ret->idnex == index){
                return ret;
            }
			ret = ret->next;
        }
	}

	List::content& List::operator[](uint32_t index) const {
		if (index > size() || index <= 0)
			throw std::out_of_range("Error memory access\a");

		list* ret = begin; // Возвращаемый экземпляр структуры

        while (ret) {
            if (ret->index == index){
                return ret;
            }
            ret = ret->next;
        }
	}

	void List::clear() noexcept {
		if (begin == NULL) {
			return;
		}
		list* deleter = begin;
		list* temp;

		while (deleter->next) {
			temp = deleter;
			deleter = deleter->next;
			delete temp;
		}

		begin = NULL;
	}

	void List::resize(uint32_t newSize, uint32_t value) noexcept {
	    // TODO
		list* parser = begin;
		while (parser) {
			if (newSize > size()) {
				push_back(value);
			} else if (newSize < size()) {
				pop_back();
			}
			parser = parser->next;
		}
	}

	void List::resize(uint32_t NewSize) noexcept {
        resize(NewSize, 0);
    }

	void List::reverse() {
		if (begin == NULL) {
			return;
		}

		for (uint32_t start(1), stop(size()); start <= stop; ++start, --stop) {
			std::swap((*this)[start], (*this)[stop]);
		}
	}

	content List::find(int32_t value) const noexcept {
	    return *begin;
	}
}
#endif // !_LIST_CPP

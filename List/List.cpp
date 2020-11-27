#pragma once
#ifndef _LIST_CPP
#define _LIST_CPP

#include "List.h"


namespace SLL {
	std::ostream& operator<<(std::ostream& os, const content& _val) noexcept {
		return os << _val.value;
	}
	std::ostream& operator<<(std::ostream& os, const list& _val) noexcept {
		return os << _val.value;
	}
	content& content::operator=(int32_t _val) noexcept {
		value = _val;
		return *this;
	}

	List::List() noexcept {
	    begin = nullptr;
	}
	List::List(const List& cp) noexcept {
	    if (begin != nullptr){
	        clear();
	    }
	    *begin = *cp.begin;
	}
	List::List(const int32_t *arr, uint32_t size) noexcept {
	    begin = nullptr;
	    for (auto i(0); i < size; ++i){
	        push_back(arr[i]);
	    }

	    Indexation();
	}
	List::List(uint32_t size, int32_t value) noexcept {
	    begin = nullptr;
        for (auto i(0); i < size; ++i){
            push_back(value);
        }
        Indexation();
	}
    List &List::operator()(const List& cp) noexcept {
        if (begin != nullptr){
            clear();
        }
        *begin = *cp.begin;
        return *this;
    }
    List &List::operator=(const List& cp) noexcept {
        if (begin != nullptr){
            clear();
        }
        *begin = *cp.begin;
        return *this;
    }
    List::~List() noexcept {
        if (begin == nullptr) {
            return;
        }

        list* deleting = begin;
        list* temp;

        while (deleting->next) {
            temp = deleting;
            deleting = deleting->next;
            delete temp;
        }

        begin = nullptr;
    }

	void List::Indexation() noexcept {
		if (begin == nullptr) {
			return;
		}
		list* iter = begin;
        uint32_t index = 0;

        while(iter){
            iter->value.index = index;
            ++index;
        }
	}

    void List::push		(int32_t _value) noexcept {
        list* ins = new list; // Äîáàâëÿåìûé ýëåìåíò
        ins->value.value = _value;
        ins->next = nullptr;

        list* t = begin;
        if (begin == nullptr) {
            ins->value.index = 1;
            begin = ins;
            return;
        }

        if (ins->value.value <= t->value.value) {
            ins->next = t;
            begin = ins;
            Indexation();
            return;
        }

        list* t1 = t->next;
        while (t != nullptr) {
            if (t->next == nullptr) {
                t->next = ins;
                Indexation();
                return;
            }

            if (ins->value.value >= t->value.value && ins->value.value <= t1->value.value) {
                t->next = ins;
                ins->next = t1;
                Indexation();
                return;
            }

            t = t->next;
            t1 = t->next;
        }
    }
	void List::push_back(int32_t value) noexcept {
		list* inserter = new list;

		inserter->value.value = value;
		inserter->next = nullptr;

		if (begin == nullptr) {
			begin = inserter;
            begin->value.index = 0;
			return;
		}

		list* iter = begin;
		while (iter) {
			if (iter->next == nullptr) {
				iter->next = inserter;
				inserter->next = nullptr;
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

	void List::pop(uint32_t index) {
	    if (index >= size() || index < 0){
	        throw std::out_of_range("Wrong index");
	    }
	    list* deleter = begin;
	}
	void List::pop_back() noexcept {
		if (begin == nullptr) {
			return;
		}
		list* t = begin;
		list* t1 = t->next;

		while (t) {
			if (t1->next == nullptr) {
				delete t1;
				t->next = nullptr;
				return;
			}
			t = t->next;
			t1 = t1->next;
		}
	}
	void List::pop_front() noexcept {
		if (begin == nullptr) {
			return;
		}
		list* pop = begin;
		begin = begin->next;
		delete pop;
		Indexation();
	}
    void List::remove	(int32_t _value) {
        if (begin == nullptr) {
            throw std::runtime_error("Begin is null");
        }

        list* t = begin;

        if (t->value.value == _value) {
            begin = t->next;
            delete t;
            Indexation();
            return;
        }

        list*  t1 = t->next;
        while (t1 != nullptr) {
            if (t1->value.value == _value) {
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

	uint32_t List::size()	const noexcept {
		if (begin == nullptr) {
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
	bool List::empty()	const noexcept {
		return (begin == nullptr);
	}

	double	List::averege() const noexcept {
		if (begin == nullptr) {
			return 0;
		}

		return double(sum() / size());
	}
	int32_t List::max()		const noexcept {
		if (begin == nullptr) {
			return 0;
		}

		list* temp = begin;
		auto result = INT64_MIN;

		while (temp != nullptr) {
			if (temp->value.value > result) {
				result = temp->value.value;
			}
			temp = temp->next;
		}
		return result;
	}
	int32_t List::min()	const noexcept {
		if (begin == nullptr) {
			return 0;
		}

		list* temp = begin;
		auto result = INT64_MAX;

		while (temp) {
			if (temp->value.value < result) {
				result = temp->value.value;
			}
			temp = temp->next;
		}

		return result;
	}
	int32_t List::sum() const noexcept {
	    if (begin == nullptr){
	        return 0;
	    }

	    auto* iter = begin;
	    int32_t res = 0;

	    while (iter) {
	        res += iter->value.value;
	        iter = iter->next;
	    }

	    return res;
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
	list* List::_end()   const noexcept {
		if (begin == nullptr) {
			return nullptr;
		}
		list* end = begin;

		while (end) {
			if (end->next == nullptr) {
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
		if (begin == nullptr) {
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
		os << "nullptr" << std::endl;

		print = value.begin;

		while (print) {
			os << print->value.index << " -> ";
			print = print->next;
		}
		os << "nullptr" << std::endl;
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
		if (value.begin == nullptr) {
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
		if (begin == nullptr) {
			return;
		}
		list* deleter = begin;
		list* temp;

		while (deleter->next) {
			temp = deleter;
			deleter = deleter->next;
			delete temp;
		}

		begin = nullptr;
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
		if (begin == nullptr) {
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

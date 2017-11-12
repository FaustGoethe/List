#include "List.h"

namespace SLL
{
	 List::List(){
		begin = NULL;
	}
	 List::List(const List& v){
		List::~List();
		begin = v.begin;
	}
	 List::List(const int* arr, int size) {
		begin = NULL;

		for (int i(0); i < size; i++) {
			push_front(arr[i]);
		}
	}
	 List::~List(){
		 if (begin == NULL) {
			 return;
		 }
	
		list* deleting = begin;
		list* temp;

		while (deleting){
			temp = deleting;
			deleting = deleting->next;
			delete temp;
		}

		begin = NULL;
	}

	 List& List::push(int push_value){
		list* ins = new list; // Добавляемый элемент
		ins->value.key = push_value;
		ins->next = NULL;

		list* t = begin;
		if (begin == NULL){
			ins->value.index = 1;
			begin = ins;
			delete ins;
			return *this;
		}

		if (ins->value.key <= t->value.key){
			ins->next = t;
			begin = ins;
			Indexation();
			delete ins;
			return *this;
		}

		list* t1 = t->next;
		while (t != NULL){

			if (t->next == NULL){
				t->next = ins;
				Indexation();
				delete ins;
				return *this;
			}

			if (ins->value.key >= t->value.key && ins->value.key <= t1->value.key){
				t->next = ins;
				ins->next = t1;
				Indexation();
				delete ins;
				return *this;
			}

			t = t->next;
			t1 = t->next;
		}
		delete ins;
	}
	
	 List& List::remove(int remove_value){
		if (begin == NULL)
			throw std::runtime_error("The element can't be remove, because begin == null\a");

		list* t = begin;

		if (t->value.key == remove_value){
			begin = t->next;
			delete t;
			Indexation();
			return *this;
		}

		list*  t1 = t->next;
		while (t1 != NULL){
			if (t1->value.key == remove_value){
				t->next = t1->next;
				delete t1;
				Indexation();
				return *this;
			}
			t = t1;
			t1 = t1->next;
		}
		throw std::runtime_error("Element not found");
	}
	
	 int List::remove_at_index(size_t remove_index){
		 if (begin == NULL) {
			 throw std::runtime_error("The element can't be remove, because begin == null\a");
		 }
		int temp;

		list* t = begin;
		list*  t1 = t->next;

		if (t->value.index == remove_index){
			temp = t->value.key;
			begin = t->next;
			delete t;
			Indexation();
			return temp;
		}

		while (t1 != NULL){
			if (t1->value.index == remove_index){
				temp = t1->value.key;
				t->next = t1->next;
				delete t1;
				Indexation();
				return temp;
			}
			t = t1;
			t1 = t1->next;
		}
		return { 0 };
	}
	
	 List& List::push_back(int push_value){
		list* ins = new list;
		ins->value.key = push_value;
		ins->next = NULL;

		if (begin == NULL){
			begin = ins;
			Indexation();
			return *this;
		}

		list* temp = begin;

		for(;;) {
			if (temp->next == NULL){
				temp->next = ins;
				Indexation();
				return *this;
			}
			temp = temp->next;
		}
		
	}
	
	 List& List::push_front(int push_value){
		list* ins = new list;
		ins->value.key = push_value;
		ins->next = begin;
		begin = ins;
		Indexation();
		return *this;
	}
	
	 size_t List::size() const{
		if (begin == NULL)
			return 0;
		list* temp = begin;
		size_t result = 0;
		while (temp)
		{
			result++;
			temp = temp->next;
		}
		return result;
	}

	 void List::fout(const std::string& FileName)const{
		if (begin == NULL)
			throw std::runtime_error("This list can't be output, because begin == null\a");

		std::ofstream fout;
		list* print = begin;

		fout.open(FileName);

		fout << size() << std::endl;

		for (size_t i(0); i < size() - 1; i++){
			fout << print->value.key << std::endl;
			print = print->next;
		}
		fout << print->value.key;
	}
	
	 List& List::fin(const std::string& FileName){
		std::ifstream fin;
		fin.open(FileName);
		
		if (fin.is_open() != true)
			throw std::runtime_error("The file is not opened\a");

		int List_size;

		fin >> List_size;
		
		int AddValue = 0;

		for (int i(0); i < List_size; i++){
			fin >> AddValue;
			push_back(AddValue);
		}
		Indexation();
		return *this;
	}
	
	 size_t List::find(int key){
		for (size_t i(1); i <= size(); i++)
			if ((*this)[i].key == key)
				return (*this)[i].index;
		return 0;
	}

	 List& List::key_sort_reverse_bubble(){
		list* temp = begin;
		content* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].key < Arr[j].key)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->value = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	 List& List::index_sort_bubble(){
		list* temp = begin;
		content* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].index > Arr[j].index)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->value = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	 List& List::index_sort_reverse_bubble(){
		list* temp = begin;
		content* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].index < Arr[j].index)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->value = Arr[i];
			temp = temp->next;
		}
		return *this;
	}

	 double List::averege() const{
		if (begin == NULL)
			return 0;

		list* temp = begin;

		auto i = 0;

		while (temp != NULL){
			i += temp->value.key;
			temp = temp->next;
		}

		return i / size();
	}
	
	 int List::max()const{
		if (begin == NULL)
			return 0;

		list* temp = begin;
		int result = 0;
		while (temp != NULL)
		{
			if (temp->value.key >= result)
				result = temp->value.key;
			
			temp = temp->next;
		}
		return result;
	}
	
	 int List::min()const{
		if (begin == NULL)
			return 0;

		list* temp = begin;
		int result = LONG_MAX;

		while (temp != NULL)
		{
			if (temp->value.key <= result)
				result = temp->value.key;
			
			temp = temp->next;
		}
		if (result == LONG_MAX)
			result = 0;
		return result;
	}
	
	 void List::Indexation(){
		if (begin == NULL)
			return;
		list* temp = begin;

		for (size_t i(0); i < size(); i++)
		{
			temp->value.index = (i + 1);
			temp = temp->next;
		}
	}
	
	 List::content* List::Array(){
		content* result = new content[size()];
		list* temp = begin;

		for (size_t i(0); i < size(); i++)
		{
			result[i] = temp->value;
			temp = temp->next;
		}
		return result;
	}
	
	 std::ostream& operator<<(std::ostream& os,const  List& v){
		SLL::List::list* print = v.begin;

		while (print != NULL)
		{
			os << print->value.key << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;

		print = v.begin;

		while (print != NULL)
		{
			os << print->value.index << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;

		os << std::endl;
		os.setf(std::ios_base::fixed, std::ios_base::floatfield);
		os.precision(2);

		os << "Среднее арифметическое списка: " << v.averege() << std::endl;
		os << "Максимальное значение списка: " << v.max() << std::endl;
		os << "Минимальное значение списка: " << v.min() << std::endl;
		os << std::endl;
		return os;
	}
	
	 std::istream& operator>>(std::istream& os, List& v)
	{
		if (v.begin == NULL)
			return os;
		for (size_t i(0); i < v.size(); i++)
		{
			std::cout << "Введите значение " << i + 1 << " элемента списка: ";
			os >> v[i+1].key;
		}
		return os;
	}

	 List::content& List::operator[](size_t index) {
		if (index > size() || index <= 0)
			throw std::runtime_error("Error memory access\a");

		int temp = 1;
		list* ret = begin; // Возвращаемый экземпляр структуры

		for(;;)
		{
			if (temp == index)
				return ret->value;
			
			temp++;
			ret = ret->next;
		}
	}
	 List::content& List::operator[](size_t index) const {
		if (index > size() || index <= 0)
			throw std::runtime_error("Error memory access\a");

		int temp = 1;
		list* ret = begin; // Возвращаемый экземпляр структуры

		for (;;)
		{
			if (temp == index)
				return ret->value;

			temp++;
			ret = ret->next;
		}
	}
	
}
using namespace SLL;
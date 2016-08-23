#include "List.h"

namespace SLL
{
	List::List()
	{
		begin = NULL;
		status.Encryption_status = false;
		status.key = "";
	}
	List::List(const List& v)
	{
		begin = v.begin;
		status.Encryption_status = v.status.Encryption_status;
		status.key = v.status.key;
	}
	List::~List()
	{
		if (begin == NULL)
			return;

		list* p = begin;
		list* t;

		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
		begin = NULL;
	}

	void List::Insert(const size_t a)
	{
		list* ins = new list;
		ins->a.key = a;
		ins->next = NULL;

		list* t = begin;
		if (begin == NULL)
		{
			begin = ins;
			Indexation();
			return;
		}

		if (ins->a.key <= t->a.key)
		{
			ins->next = t;
			begin = ins;
			Indexation();
			return;
		}
		list* t1 = t->next;
		while (t != NULL)
		{
			if (t->next == NULL)
			{
				t->next = ins;
				Indexation();
				return;
			}

			if (ins->a.key >= t->a.key && ins->a.key <= t1->a.key)
			{
				t->next = ins;
				ins->next = t1;
				Indexation();
				return;
			}

			t = t->next;
			t1 = t->next;
		}
	}
	void List::Delete(const size_t a)
	{
		if (begin == NULL)
			throw std::runtime_error(BAD_BEGIN);
		list* t = begin;

		if (t->a.key == a)
		{
			begin = t->next;
			delete t;
			Indexation();
			return;
		}
		list*  t1 = t->next;
		while (t1 != NULL)
		{
			if (t1->a.key == a)
			{
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
	int List::IndexDelete(const int value)
	{
		if (begin == NULL)
			throw std::runtime_error(BAD_BEGIN);
		
		int temp = 0;

		list* t = begin;
		list*  t1 = t->next;

		if (t->a.index == value)
		{
			temp = t->a.key;
			begin = t->next;
			delete t;
			Indexation();
			return temp;
		}

		while (t1 != NULL)
		{
			if (t1->a.index == value)
			{
				temp = t1->a.key;
				t->next = t1->next;
				delete t1;
				Indexation();
				return temp;
			}
			t = t1;
			t1 = t1->next;
		}
		throw std::runtime_error("Element not found");
	}
	List& List::AddEnd(const size_t v)
	{
		list* ins = new list;
		ins->a.key = v;
		ins->next = NULL;

		if (begin == NULL)
		{
			begin = ins;
			Indexation();
			return *this;
		}

		list* temp = begin;

		while (1)
		{
			if (temp->next == NULL)
			{
				temp->next = ins;
				Indexation();
				return *this;
			}
			temp = temp->next;
		}
		
	}
	List& List::AddBegin(const size_t v)
	{
		list* ins = new list;
		ins->a.key = v;
		ins->next = begin;
		begin = ins;
		Indexation();
		return *this;
	}
	size_t List::size() const
	{
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
	List& List::Encryption()
	{
		if (begin == NULL)
			throw std::runtime_error(BAD_BEGIN);

		if (status.key == "")
			throw std::bad_alloc();

		list* temp = begin;

		if (status.Encryption_status == true)
		{
			while (temp != NULL)
			{
				for (size_t i(0); i < status.key.size(); i++)
					temp->a.key ^= status.key[i];
				temp = temp->next;
			}
			status.Encryption_status = false;
			return *this;
		}

		while (temp != NULL)
		{
			for (size_t i(0); i < status.key.size(); i++)
				temp->a.key ^= status.key[i];
			temp = temp->next;
		}
		status.Encryption_status = true;
		return *this;
	}
	void List::Output_with_file(const std::string& FileName)const
	{
		if (begin == NULL)
			throw std::runtime_error(BAD_BEGIN);

		std::ofstream fout;
		list* print = begin;

		fout.open(FileName);

		fout << size() << std::endl;

		for (size_t i(0); i < size() - 1; i++)
		{
			fout << print->a.key << std::endl;
			print = print->next;
		}
		fout << print->a.key;

		if (status.Encryption_status == true)
			fout << std::endl << status.key;
		std::cout << "Список успешно выведен в файл!" << std::endl;
	}
	void Input_with_file(List& result,const std::string& FileName)
	{
		std::ifstream fin;
		fin.open(FileName);
		
		if (fin.is_open() != true)
			throw std::runtime_error("Файл не открылся");

		int List_size;

		fin >> List_size;
		
		size_t AddValue = 0;

		for (int i(0); i < List_size; i++)
		{
			fin >> AddValue;
			result.AddEnd(AddValue);
		}
		if (!fin.eof())
		{
			fin >> result.status.key;
			result.status.Encryption_status = true;
		}
		result.Indexation();
	}
	size_t List::KeyFind(const size_t key)
	{
		for (size_t i(1); i <= size(); i++)
			if ((*this)[i].key == key)
				return (*this)[i].index;
		return 0;
	}

	List& List::KeySort()
	{
		list* temp = begin;
		A* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].key > Arr[j].key)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->a = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	List& List::keySortMin()
	{
		list* temp = begin;
		A* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].key < Arr[j].key)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->a = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	List& List::IndexSort()
	{
		list* temp = begin;
		A* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].index > Arr[j].index)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->a = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	List& List::IndexSortMin()
	{
		list* temp = begin;
		A* Arr = Array();

		for (size_t i(0); i < size(); i++)
			for (size_t j(0); j < i; j++)
				if (Arr[i].index < Arr[j].index)
					std::swap(Arr[i], Arr[j]);

		for (size_t i(0); i < size(); i++)
		{
			temp->a = Arr[i];
			temp = temp->next;
		}
		return *this;
	}
	
	ld List::Averege() const
	{
		if (begin == NULL)
			return 0;

		list* temp = begin;

		double i = 0;

		while (temp != NULL)
		{
			i += (double)temp->a.key;
			temp = temp->next;
		}

		return i / size();
	}
	ld List::GeometryMean() const
	{
		if (begin == NULL)
			return 0;

		list* temp = begin;
		long double i = 1;

		while (temp != NULL)
		{
			i *= (double)temp->a.key;
			temp = temp->next;
		}

		return sqrt(i);
	}
	int List::Maximum()const
	{
		if (begin == NULL)
			return 0;

		list* temp = begin;
		size_t result = 0;
		while (temp != NULL)
		{
			if ((size_t)temp->a.key >= result)
			{
				result = temp->a.key;
			}
			temp = temp->next;
		}
		return result;
	}
	int List::Minimum()const
	{
		if (begin == NULL)
			return 0;

		list* temp = begin;
		size_t result = LONG_MAX;

		while (temp != NULL)
		{
			if ((size_t)temp->a.key <= result)
			{
				result = temp->a.key;
			}
			temp = temp->next;
		}
		if (result == LONG_MAX)
			result = 0;
		return result;
	}
	void List::Indexation()
	{
		if (begin == NULL)
			return;
		list* temp = begin;

		for (size_t i(0); i < size(); i++)
		{
			temp->a.index = (i + 1);
			temp = temp->next;
		}
	}
	A* List::Array()
	{
		A* result = new A[size()];
		list* temp = begin;

		for (size_t i(0); i < size(); i++)
		{
			result[i] = temp->a;
			temp = temp->next;
		}
		return result;
	}
	
	std::ostream& operator<<(std::ostream& os,const  List& v)
	{
		SLL::list* print = v.begin;

		while (print != NULL)
		{
			os << print->a.key << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;

		print = v.begin;

		while (print != NULL)
		{
			os << print->a.index << " -> ";
			print = print->next;
		}
		os << "NULL" << std::endl;

		os << "Статус списка: ";
		if (v.status.Encryption_status == true)
		{
			os << "зашифрован" << std::endl;
			return os;
		}
		else
			os << "не зашифрован" << std::endl;
		os << std::endl;
		os.setf(std::ios_base::fixed, std::ios_base::floatfield);
		os.precision(0);

		os << "Среднее арифметическое списка: " << v.Averege() << std::endl;
		os << "Среднее геометрическое списка: " << v.GeometryMean() << std::endl;
		os << "Максимальное значение списка: " << v.Maximum() << std::endl;
		os << "Минимальное значение списка: " << v.Minimum() << std::endl;
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
	A& List::operator[](const size_t index)
	{
		if (index > size() || index <= 0)
			throw std::runtime_error("Ошибка доступа чтения памяти\a");

		int temp = 1;
		list* ret = begin;
		for(;;)
		{
			if (temp == index)
			{
				return ret->a;
			}
			temp++;
			ret = ret->next;
		}
		
	}

	std::ostream& operator<<(std::ostream& os,const A& v)
	{
		os << "Key = " << v.key << std::endl;
		return os;
	}


}
using namespace SLL;
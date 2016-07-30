#include "List.h"
namespace SinglyLinkedList
{
	List1::List1()
	{
		begin = NULL;
	}
	List1::List1(const size_t n)
	{

	}
	List1::~List1()
	{
		if (begin == NULL)
			return;

		list1* p = begin;
		list1* t;

		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
		begin = NULL;
	}

	void List1::Insert(const A& a)
	{
		list1* ins = new list1;
		ins->a = a;
		ins->next = NULL;

		list1* t = begin;
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
		list1* t1 = t->next;
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
	void List1::Delete(const A& a)
	{
		list1* t = begin;

		if (t->a.key == a.key)
		{
			begin = t->next;
			delete t;
			Indexation();
			return;
		}
		list1*  t1 = t->next;
		while (t1 != NULL)
		{
			if (t1->a.key == a.key)
			{
				t->next = t1->next;
				delete t1;
				Indexation();
				return;
			}
			t = t1;
			t1 = t1->next;
		}
	}
	size_t List1::size() const
	{
		list1* temp = begin;
		size_t result = 0;
		while (temp)
		{
			result++;
			temp = temp->next;
		}
		return result;
	}
	ld List1::Averege() const
	{
		list1* temp = begin;

		double i = 0;

		while (temp != NULL)
		{
			i += (double)temp->a.key;
			temp = temp->next;
		}

		return i / size();
	}
	ld List1::GeometryMean() const
	{
		list1* temp = begin;
		long double i = 1;

		while (temp != NULL)
		{
			i *= (double)temp->a.key;
			temp = temp->next;
		}

		return sqrt(i);
	}
	int List1::Maximum()const
	{
		list1* temp = begin;
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
	int List1::Minimum()const
	{
		list1* temp = begin;
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
	void List1::Indexation()
	{
		list1* temp = begin;

		for (size_t i(0); i < size(); i++)
		{
			temp->a.index = (i + 1);
			temp = temp->next;
		}
	}

	std::ostream& operator<<(std::ostream& os, List1& v) 
	{
		List1::list1* print = v.begin;

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

		os << "Статус спсика: ";
		
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
}
namespace list = SinglyLinkedList;
using namespace list;
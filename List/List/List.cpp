#include "List.h"
namespace Error
{
	// счетчик ошибок
	int no_of_error = 0;

	// Статус списка(создан ли он)
	bool List_Status = false;

	// Статус выводимого из файла списка
	bool Fin_status = false;

	bool Fin_List_Status = false;

	// Статус шифрования списка
	bool Encryption_Status = false;

	// Статус шифрования выведенного из файла списка
	bool Encryption_fin_Status = false;

	//Ошибка удаления
	struct Faled_to_delete
	{
		const char* name_of_error;
		const std::string error_category = "Faled to delete";
		Faled_to_delete(const char* x)
		{
			name_of_error = x;
			no_of_error++;
		}
	};

	//Список еще не создан
	struct List_not_found
	{
		const char* name_of_error;
		const std::string error_category = "List not found";
		List_not_found(const char* x)
		{
			no_of_error++;
			name_of_error = x;
		}
	};

	//Файла не существует
	struct File_not_found
	{
		const char* name_of_error;
		const std::string error_category = "File not found";
		File_not_found(const char* x)
		{
			no_of_error++;
			name_of_error = x;
		}
	};

	// Повторное создание списка
	struct List_has_been_created
	{
		const char* name_of_error;
		const std::string error_category = "List creation";
		List_has_been_created(const char* x)
		{
			no_of_error++;
			name_of_error = x;
		}
	};

	//Повторный вывод из файла
	struct Output_from_file
	{
		const char* name_of_error;
		const std::string error_category = "Repeated output from file";
		Output_from_file(const char* x)
		{
			no_of_error++;
			name_of_error = x;
		}
	};

	//Мало элементов
	struct Few_Elements
	{
		const char* name_of_error;
		const std::string error_category = "Too few elements";
		Few_Elements(const char* x)
		{
			no_of_error++;
			name_of_error = x;
		}
	};

	// Ошибка добавки
	struct Faled_to_insert
	{
		const char* name_of_error;
		const std::string error_category = "Faled to delete";
		Faled_to_insert(const char* x)
		{
			name_of_error = x;
			no_of_error++;
		}
	};

	// Ошибка сортировки
	struct Faled_to_sort
	{
		const char* name_of_error;
		const std::string error_category = "Faled to delete";
		Faled_to_sort(const char* x)
		{
			name_of_error = x;
			no_of_error++;
		}
	};
}
namespace SLL
{
	List::List()
	{
		begin = NULL;
	}
	List::List(const List& v)
	{
		begin = v.begin;
		Encryption_status = v.Encryption_status;
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
			throw Begin_is_zero();
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
		throw Element_not_found();
	}
	int List::IndexDelete(const int value)
	{
		if (begin == NULL)
			throw Begin_is_zero();
		
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
		throw Element_not_found();
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
	void List::Encryption(const std::string& key)
	{
		if (begin == NULL)
			throw Begin_is_zero();
		
		list* temp = begin;

		if (Encryption_status == true)
		{
			while (temp != NULL)
			{
				for (size_t i(0); i < key.size(); i++)
					temp->a.key ^= key[i];
				temp = temp->next;
			}
			Encryption_status = false;
			return;
		}

		if (key.size() < 5)
			throw Error::Few_Elements(" мало значений в ключе шифрования");

		while (temp != NULL)
		{
			for (size_t i(0); i < key.size(); i++)
				temp->a.key ^= key[i];
			temp = temp->next;
		}
		Encryption_status = true;
	}
	void List::Input_with_file(std::ofstream& fout, std::string& FileName, std::string& EncryptionKey)
	{
		if (begin == NULL)
			throw List::Begin_is_zero();

		list* print = begin;

		fout.open(FileName);

		fout << size() << std::endl;

		for (size_t i(0); i < size() - 1; i++)
		{
			fout << print->a.key << std::endl;
			print = print->next;
		}
		fout << print->a.key;

		if (Encryption_status == true)
			fout << std::endl << EncryptionKey;
		std::cout << "Список успешно выведен в файл!" << std::endl;
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
	void List::Indexation()const
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

	std::ostream& operator<<(std::ostream& os,  List& v)
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
		if (v.Encryption_status == true)
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
	A& List::operator[](const size_t index)
	{
		if (index > size() || index <= 0)
			throw std::runtime_error("Ошибка доступа чтения памяти");

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
}
using namespace SLL;
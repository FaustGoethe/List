#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned int ui;

struct A
{
	int index;
	int key;
};
struct List
{
	A a;
	List* next;
};

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
		const string error_category = "Faled to delete";
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
		const string error_category = "List not found";
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
		const string error_category = "File not found";
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
		const string error_category = "List creation";
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
		const string error_category = "Repeated output from file";
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
		const string error_category = "Too few elements";
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
		const string error_category = "Faled to delete";
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
		const string error_category = "Faled to delete";
		Faled_to_sort(const char* x)
		{
			name_of_error = x;
			no_of_error++;
		}
	};
}

namespace menu
{
	// Обычное меню
	void menu() 
	{
		cout << "1.Создать список" << endl;
		cout << "2.Вывод" << endl;
		cout << "3.Добавка/удаление" << endl;
		cout << "4.Ввод/ввывод из файла" << endl;
		cout << "5.Найти элемент списка" << endl;
		cout << "6.Отсортировать список" << endl;
		cout << "7.Зашифровать/расшифровать список" << endl;
		cout << "8.Выйти" << endl;
	}

	// Меню сортировки
	void SortMenu() 
	{
		cout << "1.Отсортировать значения по увеличению" << endl;
		cout << "2.Отсортировать значения по уменьшению" << endl;
		cout << "3.Отсортировать индексы по увеличению" << endl;
		cout << "4.Отсортировать индексы по уменьшению" << endl;
		cout << "5.выйти" << endl;
	}

	// Меню вывода из файла
	void FinMenu()
	{
		cout << "1.Вывести список" << endl;
		cout << "2.Добавка/удаление" << endl;
		cout << "3.Найти элемент списка" << endl;
		cout << "4.Отсортировать список" << endl;
		cout << "5.Зашифровать/расшифровать список" << endl;
		cout << "6.Выйти" << endl;
	}

	// Меню fstream
	void FstreamMenu() 
	{
		cout << "1.Ввести список в файл" << endl;
		cout << "2.Вывести список из файла" << endl;
		cout << "3.Выйти" << endl;
	}

	// Меню добавки/удаления элементов
	void ElementsMenu()
	{
		cout << "1.Добавить элемент" << endl;
		cout << "2.Удалить элемент" << endl;
		cout << "3.Удалить элемент по индексу" << endl;
		cout << "4.Выйти" << endl;
	}
}

namespace Side_functions
{
	size_t List_Size(List* begin)
	{
		size_t size = 0;
		List* temp = begin;

		while (temp != NULL)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}

	// Среднее арифметическое
	double Average(List* begin) 
	{
		if (begin == NULL)
			return 0;
		List* temp = begin;

		double i = 0;

		while (temp != NULL)
		{
			i += (double)temp->a.key;
			temp = temp->next;
		}

		return i / List_Size(begin);
	}

	// Среднее геометрическое
	long double AveregeGeometry(List* begin) 
	{
		if (begin == NULL)
			return 0;
		List* temp = begin;
		long double i = 1;

		while (temp != NULL)
		{
			i *= (double)temp->a.key;
			temp = temp->next;
		}

		return sqrt(i);
	}

	// Максимальное значение списка
	size_t Maximum(List* begin) 
	{
		if (begin == NULL)
			return 0;
		List* temp = begin;
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

	// Минимальное значение списка
	size_t Minimum(List* begin)
	{
		if (begin == NULL)
			return 0;
		List* temp = begin;
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

	//Индексация списка
	void Indexation(List** begin) 
	{
		List* temp = *begin;

		for (size_t i(0); i < List_Size(*begin); i++)
		{
			temp->a.index = (i + 1);
			temp = temp->next;
		}
	}

	//Информация о программе
	void Information_of_Programm()
	{
		system("cls");
		string version = "3.9.2", author_name = "Колобов Кирилл";
		cout << "Версия программы: " << version << endl;
		cout << "Автор пограммы: " << author_name << endl;
	}
}

namespace Main_Function
{
	// Освобождение памяти
	void Free(List** begin) 
	{
		if (*begin == NULL)
			return;

		List* p = *begin;
		List* t;

		while (p)
		{
			t = p;
			p = p->next;
			delete t;
		}
		*begin = NULL;
	}

	//Удаение по ключу
	void Delete(List** begin, const A &a)
	{
		if (*begin == NULL)
		{
			cerr << "Начало списка имеет положение NULL!\a" << endl;
			return;
		}
		List* t = *begin;

		if (t->a.key == a.key)
		{
			*begin = t->next;
			delete t;
			Side_functions::Indexation(*&begin);
			return;
		}
		List*  t1 = t->next;
		while (t1 != NULL)
		{
			if (t1->a.key == a.key)
			{
				t->next = t1->next;
				delete t1;
				Side_functions::Indexation(*&begin);
				return;
			}
			t = t1;
			t1 = t1->next;
		}
		cout << "Значение не найдено!\a" << endl;
	}

	//Удаление по индексу
	size_t IndexDelete(List** begin, const size_t index)
	{
		if (*begin == NULL)
		{
			cerr << "Список еще не создан\a" << endl;
			return -1;
		}

		size_t temp = 0;

		List* t = *begin;
		List*  t1 = t->next;

		if (t->a.index == index)
		{
			temp = t->a.key;
			*begin = t->next;
			delete t;
			Side_functions::Indexation(*&begin);
			return temp;
		}

		while (t1 != NULL)
		{
			if (t1->a.index == index)
			{
				temp = t1->a.key;
				t->next = t1->next;
				delete t1;
				Side_functions::Indexation(*&begin);
				return temp;
			}
			t = t1;
			t1 = t1->next;
		}
		cout << "Элемента с таким индексом не существует!" << endl;
		return -1;
	}

	// Печать списка
	void Print(List* begin) 
	{
		List* print = begin;

		while (print != NULL)
		{
			cout << print->a.key << " -> ";
			print = print->next;
		}
		cout << "NULL" << endl;

		print = begin;

		while (print != NULL)
		{
			cout << print->a.index << " -> ";
			print = print->next;
		}
		cout << "NULL" << endl;

		cout << "Статус спсика: ";
		if (Error::Encryption_Status == true)
		{
			cout << " зашифрован" << endl << endl;
			return;
		}
		else
			cout << " не зашифрован" << endl;
		cout << endl;
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(0);

		cout << "Среднее арифметическое списка: " << Side_functions::Average(begin) << endl;
		cout << "Среднее геометрическое списка: " << Side_functions::AveregeGeometry(begin) << endl;
		cout << "Максимальное значение списка: " << Side_functions::Maximum(begin) << endl;
		cout << "Минимальное значение списка: " << Side_functions::Minimum(begin) << endl;
		cout << endl;
	}

	void Fin_Print(List* begin) // Печать списка
	{
		if (begin == NULL)
			return;

		List* print = begin;

		while (print != NULL)
		{
			cout << print->a.key << " -> ";
			print = print->next;
		}
		cout << "NULL" << endl;

		print = begin;

		while (print != NULL)
		{
			cout << print->a.index << " -> ";
			print = print->next;
		}
		cout << "NULL" << endl;

		cout << "Статус спсика: ";
		if (Error::Encryption_fin_Status == true)
		{
			cout << " зашифрован" << endl;
			return;
		}
		else
			cout << " не зашифрован" << endl;

		cout << endl;
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(3);

		cout << "Среднее арифметическое списка: " << Side_functions::Average(begin) << endl;
		cout << "Среднее геометрическое списка: " << Side_functions::AveregeGeometry(begin) << endl;
		cout << "Максимальное значение списка: " << Side_functions::Maximum(begin) << endl;
		cout << "Минимальное значение списка: " << Side_functions::Minimum(begin) << endl;
		cout << endl;
	}

	//Инициализация списка
	void Init(List** begin, const A a[], const int leght) 
	{
		*begin = new List;
		List* end = *begin;

		(*begin)->a = a[0];
		for (int i(1); i < leght; i++)
		{
			end->next = new List;
			end = end->next;
			end->a = a[i];
			end->next = NULL;
		}
		Error::List_Status = true;
		Side_functions::Indexation(*&begin);
	}

	// Добавка элементов
	void Insert(List** begin, const A &a) 
	{
		if (Error::List_Status == false && Error::Fin_status == false)
			throw Error::List_not_found(" the list has not been created!");

		List* ins = new List;
		ins->a = a;
		ins->next = NULL;

		List* t = (*begin);
		if (*begin == NULL)
		{
			*begin = ins;
			return;
		}

		if (ins->a.key <= t->a.key)
		{
			ins->next = t;
			*begin = ins;
			Side_functions::Indexation(*&begin);
			return;
		}
		List* t1 = t->next;
		while (t != NULL)
		{
			if (t->next == NULL)
			{
				t->next = ins;
				Side_functions::Indexation(*&begin);
				return;
			}

			if (ins->a.key >= t->a.key && ins->a.key <= t1->a.key)
			{
				t->next = ins;
				ins->next = t1;
				Side_functions::Indexation(*&begin);
				return;
			}

			t = t->next;
			t1 = t->next;
		}
	}

	// Поиск элемента
	//Если элемент не найден, то результат функции 0
	size_t Count(List* begin, int* count)
	{								   
		if (Error::List_Status == false && Error::Fin_status == false)
			throw Error::List_not_found(" the list has not been created!");

		List* t = begin;
		size_t Count_Number = 0;

		while (t != NULL)
		{
			Count_Number++;
			if (t->a.key == *count)
			{
				return Count_Number;
			}
			t = t->next;
		}
		return 0;
	}

	// Шифрование списка
	void Encryption(List** begin, string& key) 
	{
		if (*begin == NULL)
		{
			cerr << "Невозможно зашифровать список! Нет элементов!\a" << endl;
			return;
		}


		List* temp = *begin;

		if (Error::Encryption_Status == true)
		{
			while (temp != NULL)
			{
				for (int i(0); i < 5; i++)
					temp->a.key ^= key[i];
				temp = temp->next;
			}
			Error::Encryption_Status = false;
			return;
		}

		cout << "Введите значения ключа шифрования: ";
		while (!(cin >> key))
		{
			cin.clear();
			cout << "Ошибка ввода\a" << endl;
			while (cin.get() != '\n');
			cout << "Введите значения ключа шифрования: ";
		}
		if (key.size() < 5)
			throw Error::Few_Elements(" мало значений в ключе шифрования");

		while (temp != NULL)
		{
			for (int i(0); i < 5; i++)
				temp->a.key ^= key[i];
			temp = temp->next;
		}
		Error::Encryption_Status = true;

	}

	// Шифрование веведенного из файла списка
	void Fin_Encryption(List** begin, string& key) 
	{
		if (*begin == NULL)
		{
			cerr << "Невозможно зашифровать список! Нет элементов!\a" << endl;
			return;
		}
		List* temp = *begin;

		if (Error::Encryption_fin_Status == true)
		{
			while (temp != NULL)
			{
				for (int i(0); i < 5; i++)
					temp->a.key ^= key[i];
				temp = temp->next;
			}
			Error::Encryption_fin_Status = false;
			return;
		}

		cout << "Введите значения ключа шифрования: ";
		while (!(cin >> key))
		{
			cin.clear();
			cout << "Ошибка ввода\a" << endl;
			while (cin.get() != '\n');
			cout << "Введите значения ключа шифрования: ";
		}
		if (key.size() < 5)
			throw Error::Few_Elements(" мало значений в ключе шифрования");

		while (temp != NULL)
		{
			for (int i(0); i < 5; i++)
				temp->a.key ^= key[i];
			temp = temp->next;
		}

		Error::Encryption_fin_Status = true;
	}
}

namespace Inspection_input
{
	//Ввод количества элементов
	void Number_of_elements(int* N)
	{
		cout << "Введите количество элементов списка: ";
		while (!(cin >> *N) || *N < 2)
		{
			cerr << "Количество элементов списка должно быть больше двух\a";
			cin.clear();
			while (cin.get() != '\n');
			system("cls");
			cout << "Введите количество элементов списка: ";
		}

	}

	//Заполнение списка
	void Filling_list(A a[], const int leght)
	{
		if (Error::List_Status == true)
			throw Error::List_has_been_created(" The list has been created");

		for (int i(0); i < leght; i++)
		{
			cout << "Введите значение " << (i + 1) << " элемента списка: ";
			while (!(cin >> a[i].key))
			{
				cerr << "Недопустимое значение!\a";
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введите значение " << (i + 1) << " элемента списка: ";
			}
		}
	}

	//Проверка ввода
	void Inspection_input(A &a)
	{
		cout << "Введите значение элемента списка: ";
		while (!(cin >> a.key))
		{
			cerr << "Недопустимое значение!\a";
			cin.clear();
			while (cin.get() != '\n');
			cout << "Введите значение элемента списка: ";
		}
	}

	template<typename T>
	void Inpection_Input(T& a)
	{
		
		while (!(cin >> a) || a <= 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Введите индекс элемента, который хотите удалить: ";

		}
	}
}

namespace Fstream
{
	//Ввод списка в файл
	void Fout(ofstream &fout, List* begin, string &key)
	{
		if (begin == NULL)
		{
			cerr << "Невозможно зашифровать список! Нет элементов!\a" << endl;
			return;
		}
		List* print = begin;
		string FoutStr;

		cout << "Введите имя файла, в который будет вводится список: ";
		cin >> FoutStr;

		fout.open(FoutStr);

		fout << Side_functions::List_Size(*&begin) << endl;

		while (print != NULL)
		{
			fout << print->a.key << endl;
			print = print->next;
		}

		if (Error::Encryption_Status == true)
			fout << key;
		cout << "Список успешно выведен в файл!" << endl;
	}

	//Сохранение изменений после работы с выведенным из файла списком
	void Fout2(ofstream &fout, List* begin, string &str,string &key)
	{
		List* print = begin;
		fout.open(str);

		fout << Side_functions::List_Size(begin) << endl;

		while (print != NULL)
		{
			fout << print->a.key << endl;
			print = print->next;
		}
		if (Error::Encryption_fin_Status == true)
			fout << key;
		
	}

	//Вывод списка из файла
	void Fin(ifstream &fin, List** begin1, string* FinStr,string &key)
	{
		cout << "Введите имя файлa, из которого будет выводиться список: ";
		cin >> (*FinStr);
		fin.open(*FinStr);

		if (fin.is_open() != true)
			throw Error::File_not_found(" this file does not exist");

		*begin1 = new List;
		List* end = (*begin1);

		int List_size = 0;
		Error::Fin_status = true;

		fin >> List_size;
		fin >> (*begin1)->a.key;

		(*begin1)->next = NULL;
		for(int i(1); i < List_size; i++)
		{
			end->next = new List;
			end = end->next;
			fin >> end->a.key;
			end->next = NULL;
		}
		Side_functions::Indexation(*&begin1);
		if (!fin.eof())
		{
			fin >> key;
			Error::Encryption_fin_Status = true;
		}
	}
}

namespace Index_Sort
{
	//Сортировка индексов по увеличению
	void ShellSort_index(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].index < a[j].index)
					swap(a[j], a[i]);
	}

	//Сортировка индексов по уменьшкнию
	void ShellSort_index_Min(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].index > a[j].index)
					swap(a[j], a[i]);
	}

	//Выбор сортировки
	void IndexSort(List** begin, A arr[], const char c, const int size)
	{
		List* temp = *begin;
		int i(0);

		while (temp != NULL)
		{
			arr[i] = temp->a;
			temp = temp->next;
			i++;
		}

		switch (c)
		{
		case 51:
			ShellSort_index(arr, size);
			break;

		case 52:
			ShellSort_index_Min(arr, size);
			break;
		}

		temp = *begin;
		i = 0;
		while (temp != NULL)
		{
			temp->a = arr[i];
			temp = temp->next;
			i++;
		}
	}
}

namespace Key_Sort
{
	//Сортировка ключей по увеличению
	void ShellSort_key(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].key < a[j].key)
					swap(a[j], a[i]);
	}

	//Сортировка ключей по уменьшкнию
	void ShellSort_key_min(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].key > a[j].key)
					swap(a[j], a[i]);
	}

	void Key_Sort(List** begin, const char c)
	{
		if (*begin == NULL)
			return;

		if (Side_functions::List_Size(*begin) <= 1)
			throw Error::Few_Elements(" невозможно отсортировать!");

		List* temp = (*begin);

		int Leght_List = Side_functions::List_Size(*begin); // Размер списка

		A *arr = new A[Leght_List];

		for (int i(0); i < Leght_List; i++)
		{
			arr[i] = temp->a;
			temp = temp->next;
		}

		temp = *begin;
		int i(0);

		switch (c)
		{
		case 49:
			ShellSort_key(arr, Leght_List);
			while (temp != NULL)
			{
				temp->a = arr[i];
				i++;
				temp = temp->next;
			}

			i = 0;
			temp = *begin;

			break;
		case 50:
			ShellSort_key_min(arr, Leght_List);
			while (temp != NULL)
			{
				temp->a = arr[i];
				i++;
				temp = temp->next;
			}
			break;
		}

		delete[] arr;
	}
}

namespace Distribution
{
	void DistrElements(List** begin)
	{
		if (Error::List_Status == false && Error::Fin_status == false)
			throw Error::List_not_found(" the list has not been created!"); // Если список не создан

		char c;

		do
		{
			Main_Function::Print(*begin);
			menu::ElementsMenu();
			c = (char)_getch();

			system("cls");
			switch (c)
			{
			case 49:
				if (Error::Encryption_Status == true)
				{
					cerr << "Невозможно добавить элемент в зашифрованный список\a" << endl;
					Error::no_of_error++;
					break;
				}
				A a;
				Inspection_input::Inspection_input(a);
				Main_Function::Insert(*&begin, a);
				Side_functions::Indexation(*&begin);

				break;
			case 50:
				if (Error::Encryption_Status == true)
				{
					cerr << "Невозможно удалить элемент из зашифрованного списка\a" << endl;
					Error::no_of_error++;
					break;
				}
				A b;
				Inspection_input::Inspection_input(b);
				Main_Function::Delete(*&begin, b);
				break;

			case 51:
				if (Error::Encryption_Status == true)
				{
					cerr << "Невозможно удалить элемент из зашифрованного списка\a" << endl;
					Error::no_of_error++;
					break;
				}
				size_t pv;
				cout << "Введите индекс элемента, который хотите удалить: ";
				Inspection_input::Inpection_Input(pv);
				if (pv <= 0 || pv > Side_functions::List_Size(*begin))
				{
					cout << "Индекс должен быть больше нуля и меньше " << Side_functions::List_Size(*begin) << '\a' << endl;
					break;
				}
				system("cls");
				cout << "Был удален элемент с ключом: " << Main_Function::IndexDelete(*&begin, pv) << endl << endl;
				break;
			case 52:
				break;
			default:
				break;
			}

		} while (c != 52);
	}

	void DistrSort(List** begin)
	{
		if (Error::List_Status == false && Error::Fin_status == false)
			throw Error::List_not_found(" the list has not been created!"); // Если список не создан

		A* arr = new A[Side_functions::List_Size(*begin)]; // Массив для сортировки

		char c; // Выбор пунктов меню
		int size = Side_functions::List_Size(*begin);

		do
		{
			Main_Function::Print(*begin);

			menu::SortMenu();
			c = (char)_getch();

			system("cls");
			switch (c)
			{
			case 49:
				try
				{
					Key_Sort::Key_Sort(*&begin, c);
				}
				catch (Error::Few_Elements a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
					return;
				}
				break;
			case 50:
				try
				{
					Key_Sort::Key_Sort(*&begin, c);
				}
				catch (Error::Few_Elements a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
					return;
				}
				break;

			case 51:
				Index_Sort::IndexSort(*&begin, arr,c,size);
				break;

			case 52:
				Index_Sort::IndexSort(*&begin, arr, c,size);
				break;
			case 53:
				break;
			}
		} while (c != 53);

		delete[] arr;
	}

	void DistrFin(ifstream &fin, ofstream &fout, List** begin1)
	{
		if (Error::Fin_List_Status == true)
			throw Error::Output_from_file(" в данной версии программы повторный вывод из файла невозможен!");

		int count = 0; // Поиск элемента

		char c = 0; // Выбор пунктов меню
		char c1 = 0; //Выбор пунктов меню(сохранить изминения или нет)

		string FileName; // Имя файла, из которого будет выводится список
		string key; // Ключ шифрования

		try
		{
			Fstream::Fin(fin, *&begin1, &FileName,key);
		}
		catch (Error::File_not_found a)
		{
			cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
			return;
		}

		do
		{
			menu::FinMenu();
			c = (char)_getch();
			system("cls");
			switch (c)
			{
			case 49:
				Main_Function::Fin_Print(*begin1);
				break;

			case 50:
				DistrElements(*&begin1);
				break;
			case 51:
				cout << "Введите значение элемента, которого хотите найти: ";
				cin >> count;
				(Main_Function::Count(*begin1, &count) <= 0) ? (cout << "Значение не найдено!" << endl) : (cout << "Индекс искомого элемента: " << Main_Function::Count(*begin1, &count) << endl);
				break;

			case 52:
				DistrSort(*&begin1);
				break;
			case 53:
				Main_Function::Fin_Encryption(*&begin1, key);
				break;
			case 54:
				cout << "Хотите сохранить изменения(y/n)?" << endl;
				c1 = (char)_getch();
				switch (c1)
				{
				case 121:
					Fstream::Fout2(fout, *begin1, FileName,key);
					cout << "Изменения успешно сохранены!" << endl;
					break;
				case 110:
					cout << "Изменения не сохранены!" << endl;
					break;

				default:
					cout << "Изменения не сохранены!" << endl;
					break;
				}
				break;
			}

		} while (c != 54);
	}

	void Fsteam(ifstream &fin, ofstream &fout, List** begin1, List** begin, string& key)
	{
		char c = 0;
		do
		{
			menu::FstreamMenu();
			c = (char)_getch();
			system("cls");

			switch (c)
			{
			case 49:
				Fstream::Fout(fout, *begin,key);
				break;

			case 50:
				try
				{
					DistrFin(fin, fout, *&begin1);
				}
				catch (Error::Output_from_file a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
				}
				break;
			case 51:
				break;
			default:
				break;
			}
		} while (c != 51);
	}

	void Distr(ifstream &fin, ofstream &fout, List** begin, List** begin1)
	{
		int count = 0; // Поиск элементов
		char c; // Выбор пунктов меню
		int N;  // Изначальный размер списка

		Inspection_input::Number_of_elements(&N);
		
		A *Array = new A[N]; //Массив, из которого будет заполняться список

		string key; // Ключ шифрования
		do
		{
			menu::menu();
			c = (char)_getch();

			system("cls");
			switch (c)
			{
			case 49:
				try
				{
					Inspection_input::Filling_list(Array, N);
					Main_Function::Init(*&begin, Array, N);
					Side_functions::Indexation(*&begin);
				}
				catch (Error::List_has_been_created a)
				{
					cerr << "ERROR: " << a.error_category << ":" << a.name_of_error << '\a' << endl;
				}

				break;

			case 50:
				Main_Function::Print(*begin);
				break;

			case 51:
				try
				{
					DistrElements(*&begin);
				}
				catch (Error::List_not_found a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
				}
				break;
	
			case 52:
				Fsteam(fin, fout, *&begin1, *&begin,key);
				Error::Fin_status = false;
				Main_Function::Free(*&begin1);
				break;

			case 53:
				if (Error::List_Status == false) {
					cerr << "Error: List has not created\a" << endl;
					break;
				}
				cout << "Введите значение, которое хотите найти: ";
				cin >> count;
				try{
					Main_Function::Count(*begin, &count) <= 0 ? (cout << "Значение не найдено!" << endl) : (cout << "Индекс искомого элемента: " << Main_Function::Count(*begin, &count) << endl);
				}
				catch (Error::List_not_found a){
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
				}
				break;

			case 54:
				try
				{
					DistrSort(*&begin);
				}
				catch (Error::List_not_found a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
				}
				break;
			case 55:
				try
				{
					Main_Function::Encryption(*&begin, key);
				}
				catch (Error::Few_Elements a)
				{
					cerr << "ERROR: " << a.error_category << ": " << a.name_of_error << '\a' << endl;
				}
				break;
			case 56:
				Side_functions::Information_of_Programm();
				_getch();
				break;
			}
		} while (c != 56);
		delete[] Array;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	List* begin = NULL;

	List* begin1 = NULL;
	
	ofstream fout;
	ifstream fin;
	
	Distribution::Distr(fin, fout, &begin, &begin1);

	Main_Function::Free(&begin);

	// Возврат количества ошибок
	return Error::no_of_error; 
}

/*
* Copyright (c) by P.J. Plauger. All rights reserved.
* Consult your license regarding permissions and restrictions.
V6.50:0009 */

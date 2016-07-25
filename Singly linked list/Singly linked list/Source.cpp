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
	// ������� ������
	int no_of_error = 0; 

	// ������ ������(������ �� ��)
	bool List_Status = false; 

	// ������ ���������� �� ����� ������
	bool Fin_status = false; 

	bool Fin_List_Status = false;

	// ������ ���������� ������
	bool Encryption_Status = false; 

	// ������ ���������� ����������� �� ����� ������
	bool Encryption_fin_Status = false; 
	
	//������ ��������
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

	//������ ��� �� ������
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

	//����� �� ����������
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

	// ��������� �������� ������
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

	//��������� ����� �� �����
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

	//���� ���������
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

	// ������ �������
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

	// ������ ����������
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
	// ������� ����
	void menu() 
	{
		cout << "1.������� ������" << endl;
		cout << "2.�����" << endl;
		cout << "3.�������/��������" << endl;
		cout << "4.����/������ �� �����" << endl;
		cout << "5.����� ������� ������" << endl;
		cout << "6.������������� ������" << endl;
		cout << "7.�����������/������������ ������" << endl;
		cout << "8.�����" << endl;
	}

	// ���� ����������
	void SortMenu() 
	{
		cout << "1.������������� �������� �� ����������" << endl;
		cout << "2.������������� �������� �� ����������" << endl;
		cout << "3.������������� ������� �� ����������" << endl;
		cout << "4.������������� ������� �� ����������" << endl;
		cout << "5.�����" << endl;
	}

	// ���� ������ �� �����
	void FinMenu()
	{
		cout << "1.������� ������" << endl;
		cout << "2.�������/��������" << endl;
		cout << "3.����� ������� ������" << endl;
		cout << "4.������������� ������" << endl;
		cout << "5.�����������/������������ ������" << endl;
		cout << "6.�����" << endl;
	}

	// ���� fstream
	void FstreamMenu() 
	{
		cout << "1.������ ������ � ����" << endl;
		cout << "2.������� ������ �� �����" << endl;
		cout << "3.�����" << endl;
	}

	// ���� �������/�������� ���������
	void ElementsMenu()
	{
		cout << "1.�������� �������" << endl;
		cout << "2.������� �������" << endl;
		cout << "3.������� ������� �� �������" << endl;
		cout << "4.�����" << endl;
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

	// ������� ��������������
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

	// ������� ��������������
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

	// ������������ �������� ������
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

	// ����������� �������� ������
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

	//���������� ������
	void Indexation(List** begin) 
	{
		List* temp = *begin;

		for (size_t i(0); i < List_Size(*begin); i++)
		{
			temp->a.index = (i + 1);
			temp = temp->next;
		}
	}

	//���������� � ���������
	void Information_of_Programm()
	{
		system("cls");
		string version = "3.9.2", author_name = "������� ������";
		cout << "������ ���������: " << version << endl;
		cout << "����� ��������: " << author_name << endl;
	}
}

namespace Main_Function
{
	// ������������ ������
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

	//������� �� �����
	void Delete(List** begin, const A &a)
	{
		if (*begin == NULL)
		{
			cerr << "������ ������ ����� ��������� NULL!\a" << endl;
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
		cout << "�������� �� �������!\a" << endl;
	}

	//�������� �� �������
	size_t IndexDelete(List** begin, const size_t index)
	{
		if (*begin == NULL)
		{
			cerr << "������ ��� �� ������\a" << endl;
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
		cout << "�������� � ����� �������� �� ����������!" << endl;
		return -1;
	}

	// ������ ������
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

		cout << "������ ������: ";
		if (Error::Encryption_Status == true)
		{
			cout << " ����������" << endl << endl;
			return;
		}
		else
			cout << " �� ����������" << endl;
		cout << endl;
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(0);

		cout << "������� �������������� ������: " << Side_functions::Average(begin) << endl;
		cout << "������� �������������� ������: " << Side_functions::AveregeGeometry(begin) << endl;
		cout << "������������ �������� ������: " << Side_functions::Maximum(begin) << endl;
		cout << "����������� �������� ������: " << Side_functions::Minimum(begin) << endl;
		cout << endl;
	}

	void Fin_Print(List* begin) // ������ ������
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

		cout << "������ ������: ";
		if (Error::Encryption_fin_Status == true)
		{
			cout << " ����������" << endl;
			return;
		}
		else
			cout << " �� ����������" << endl;

		cout << endl;
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.precision(3);

		cout << "������� �������������� ������: " << Side_functions::Average(begin) << endl;
		cout << "������� �������������� ������: " << Side_functions::AveregeGeometry(begin) << endl;
		cout << "������������ �������� ������: " << Side_functions::Maximum(begin) << endl;
		cout << "����������� �������� ������: " << Side_functions::Minimum(begin) << endl;
		cout << endl;
	}

	//������������� ������
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

	// ������� ���������
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

	// ����� ��������
	//���� ������� �� ������, �� ��������� ������� 0
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

	// ���������� ������
	void Encryption(List** begin, string& key) 
	{
		if (*begin == NULL)
		{
			cerr << "���������� ����������� ������! ��� ���������!\a" << endl;
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

		cout << "������� �������� ����� ����������: ";
		while (!(cin >> key))
		{
			cin.clear();
			cout << "������ �����\a" << endl;
			while (cin.get() != '\n');
			cout << "������� �������� ����� ����������: ";
		}
		if (key.size() < 5)
			throw Error::Few_Elements(" ���� �������� � ����� ����������");

		while (temp != NULL)
		{
			for (int i(0); i < 5; i++)
				temp->a.key ^= key[i];
			temp = temp->next;
		}
		Error::Encryption_Status = true;

	}

	// ���������� ����������� �� ����� ������
	void Fin_Encryption(List** begin, string& key) 
	{
		if (*begin == NULL)
		{
			cerr << "���������� ����������� ������! ��� ���������!\a" << endl;
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

		cout << "������� �������� ����� ����������: ";
		while (!(cin >> key))
		{
			cin.clear();
			cout << "������ �����\a" << endl;
			while (cin.get() != '\n');
			cout << "������� �������� ����� ����������: ";
		}
		if (key.size() < 5)
			throw Error::Few_Elements(" ���� �������� � ����� ����������");

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
	//���� ���������� ���������
	void Number_of_elements(int* N)
	{
		cout << "������� ���������� ��������� ������: ";
		while (!(cin >> *N) || *N < 2)
		{
			cerr << "���������� ��������� ������ ������ ���� ������ ����\a";
			cin.clear();
			while (cin.get() != '\n');
			system("cls");
			cout << "������� ���������� ��������� ������: ";
		}

	}

	//���������� ������
	void Filling_list(A a[], const int leght)
	{
		if (Error::List_Status == true)
			throw Error::List_has_been_created(" The list has been created");

		for (int i(0); i < leght; i++)
		{
			cout << "������� �������� " << (i + 1) << " �������� ������: ";
			while (!(cin >> a[i].key))
			{
				cerr << "������������ ��������!\a";
				cin.clear();
				while (cin.get() != '\n');
				cout << "������� �������� " << (i + 1) << " �������� ������: ";
			}
		}
	}

	//�������� �����
	void Inspection_input(A &a)
	{
		cout << "������� �������� �������� ������: ";
		while (!(cin >> a.key))
		{
			cerr << "������������ ��������!\a";
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� �������� �������� ������: ";
		}
	}

	template<typename T>
	void Inpection_Input(T& a)
	{
		
		while (!(cin >> a) || a <= 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ������ ��������, ������� ������ �������: ";

		}
	}
}

namespace Fstream
{
	//���� ������ � ����
	void Fout(ofstream &fout, List* begin, string &key)
	{
		if (begin == NULL)
		{
			cerr << "���������� ����������� ������! ��� ���������!\a" << endl;
			return;
		}
		List* print = begin;
		string FoutStr;

		cout << "������� ��� �����, � ������� ����� �������� ������: ";
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
		cout << "������ ������� ������� � ����!" << endl;
	}

	//���������� ��������� ����� ������ � ���������� �� ����� �������
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

	//����� ������ �� �����
	void Fin(ifstream &fin, List** begin1, string* FinStr,string &key)
	{
		cout << "������� ��� ����a, �� �������� ����� ���������� ������: ";
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
	//���������� �������� �� ����������
	void ShellSort_index(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].index < a[j].index)
					swap(a[j], a[i]);
	}

	//���������� �������� �� ����������
	void ShellSort_index_Min(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].index > a[j].index)
					swap(a[j], a[i]);
	}

	//����� ����������
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
	//���������� ������ �� ����������
	void ShellSort_key(A a[], const int size)
	{
		for (int i(0); i < size; i++)
			for (int j(0); j <= i; j++)
				if (a[i].key < a[j].key)
					swap(a[j], a[i]);
	}

	//���������� ������ �� ����������
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
			throw Error::Few_Elements(" ���������� �������������!");

		List* temp = (*begin);

		int Leght_List = Side_functions::List_Size(*begin); // ������ ������

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
			throw Error::List_not_found(" the list has not been created!"); // ���� ������ �� ������

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
					cerr << "���������� �������� ������� � ������������� ������\a" << endl;
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
					cerr << "���������� ������� ������� �� �������������� ������\a" << endl;
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
					cerr << "���������� ������� ������� �� �������������� ������\a" << endl;
					Error::no_of_error++;
					break;
				}
				size_t pv;
				cout << "������� ������ ��������, ������� ������ �������: ";
				Inspection_input::Inpection_Input(pv);
				if (pv <= 0 || pv > Side_functions::List_Size(*begin))
				{
					cout << "������ ������ ���� ������ ���� � ������ " << Side_functions::List_Size(*begin) << '\a' << endl;
					break;
				}
				system("cls");
				cout << "��� ������ ������� � ������: " << Main_Function::IndexDelete(*&begin, pv) << endl << endl;
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
			throw Error::List_not_found(" the list has not been created!"); // ���� ������ �� ������

		A* arr = new A[Side_functions::List_Size(*begin)]; // ������ ��� ����������

		char c; // ����� ������� ����
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
			throw Error::Output_from_file(" � ������ ������ ��������� ��������� ����� �� ����� ����������!");

		int count = 0; // ����� ��������

		char c = 0; // ����� ������� ����
		char c1 = 0; //����� ������� ����(��������� ��������� ��� ���)

		string FileName; // ��� �����, �� �������� ����� ��������� ������
		string key; // ���� ����������

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
				cout << "������� �������� ��������, �������� ������ �����: ";
				cin >> count;
				(Main_Function::Count(*begin1, &count) <= 0) ? (cout << "�������� �� �������!" << endl) : (cout << "������ �������� ��������: " << Main_Function::Count(*begin1, &count) << endl);
				break;

			case 52:
				DistrSort(*&begin1);
				break;
			case 53:
				Main_Function::Fin_Encryption(*&begin1, key);
				break;
			case 54:
				cout << "������ ��������� ���������(y/n)?" << endl;
				c1 = (char)_getch();
				switch (c1)
				{
				case 121:
					Fstream::Fout2(fout, *begin1, FileName,key);
					cout << "��������� ������� ���������!" << endl;
					break;
				case 110:
					cout << "��������� �� ���������!" << endl;
					break;

				default:
					cout << "��������� �� ���������!" << endl;
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
		int count = 0; // ����� ���������
		char c; // ����� ������� ����
		int N;  // ����������� ������ ������

		Inspection_input::Number_of_elements(&N);
		
		A *Array = new A[N]; //������, �� �������� ����� ����������� ������

		string key; // ���� ����������
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
				cout << "������� ��������, ������� ������ �����: ";
				cin >> count;
				try{
					Main_Function::Count(*begin, &count) <= 0 ? (cout << "�������� �� �������!" << endl) : (cout << "������ �������� ��������: " << Main_Function::Count(*begin, &count) << endl);
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

	// ������� ���������� ������
	return Error::no_of_error; 
}

/*
* Copyright (c) by P.J. Plauger. All rights reserved.
* Consult your license regarding permissions and restrictions.
V6.50:0009 */

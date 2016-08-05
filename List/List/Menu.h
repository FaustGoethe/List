#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <iostream>
namespace Menu
{
	using std::cout;
	using std::endl;
	
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
using namespace Menu;
#endif
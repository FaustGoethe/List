#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <iostream>
namespace MENU
{
	using std::cout;
	using std::endl;
	
	// ������� ����
	void menu(){
		cout << "1.Create list"			<< endl;
		cout << "2.Show list"			<< endl;
		cout << "3.Add/remove"			<< endl;
		cout << "4.File"				<< endl;
		cout << "5.Find the element"	<< endl;
		cout << "6.Sort list"			<< endl;
		cout << "7.Reverse list"		<< endl;
		cout << "8.Resize"				<< endl;
		cout << "9.Exit"				<< endl;
	}

	// ���� ����������
	void SortMenu(){
		cout << "1.Sort value up"	<< endl;
		cout << "2.Sort value down" << endl;
		cout << "3.Sort index up"	<< endl;
		cout << "4.Sort index down" << endl;
		cout << "5.Exit"			<< endl;
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
	void FstreamMenu(){
		cout << "1.Into file" << endl;
		cout << "2.From file" << endl;
		cout << "3.Exit" << endl;
	}

	// ���� �������/�������� ���������
	void ElementsMenu(){
		cout << "1.Add"					<< endl;
		cout << "2.Remove"				<< endl;
		cout << "3.Remove from index"	<< endl;
		cout << "4.Exit"				<< endl;
	}
}
#endif
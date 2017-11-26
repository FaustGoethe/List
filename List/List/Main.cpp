#include <iostream>
#include <conio.h>
#include <fstream>
#include "List.h"
#include "Menu.h"

#define FILE "list.txt"

using std::cout;
using std::endl;
using std::cin;

void add_remove(SLL::List& obj) {
	char c;

	int t;
	for (;;){
		MENU::ElementsMenu();
		c = (char)_getch();
		system("cls");

		switch (c) {
		case '1':
			cout << "Enter adding value: ";
			cin >> t;
			obj.push(t);
			break;
		case '2':
			cout << "Enter deleting value: ";
			cin >> t;
			obj.remove(t);
			break;
		case '3':
			cout << "Enter deleting index: ";
			cin >> t;
			obj.remove_at_index(t);
			break;
		case '4': return;

		default: cout << "Bad opcode!\a"; break;
		}
		system("cls");
	}
}
void file(SLL::List& obj) {
	char c;

	std::ifstream fin;
	std::ofstream fout;

	for (;;) {
		MENU::FstreamMenu();
		c = (char)_getch();
		system("cls");

		switch (c) {
		case '1': 
			fout.open(FILE);
			fout << obj;	
			break;
		case '2':
			fin.open(FILE);
			try {
				fin >> obj;
			}
			catch (const std::exception& excp) {
				std::cerr << excp.what();
			}
			break;
		case '3': 
			return;

		default: cout << "Bad opcode!\a"; break;
		}
	}
}
void sort(SLL::List& obj) {
	char c;

	for (;;) {
		MENU::SortMenu();
		c = (char)_getch();
		system("cls");

		switch (c) {
		case '1': obj.ksort();	break;
		case '2': obj.rksort(); break;
		case '3': obj.isort();	break;
		case '4': obj.irsort();	break;
		case '5': return;

		default: cout << "Bad opcode!\a"; break;
		}
	}
}

void general(SLL::List& obj) {
	char c;

	for(;;) {
		MENU::menu();
		c = (char)_getch();
		system("cls");

		switch (c) {
		case '1': cin >> obj;			break;
		case '2': cout << obj; _getch(); break;
		case '3': add_remove(obj);		break;
		case '4': file(obj);			break;
		case '5': /*find*/				break;
		case '6': sort(obj);			break;
		case '7': obj.reverse();		break;
		case '8':						break;
		case '9': return;

		default: cout << "Bad opcode!\a"; break;
		}

		
		system("cls");
	} 
}

int main(int argc, char* argv[]){
	SLL::List a;
	try {
		general(a);
	}
	catch (const std::exception& excp) {
		cout << excp.what();
	}
	_getch();
	return 0;
}
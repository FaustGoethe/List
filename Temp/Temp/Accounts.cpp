#include "Accounts.h"
#include <iostream>

namespace Programm
{
	Accounts::Accounts()
	{
		name = "NoName";
		money = 0;
		status = true;
		login = false;
		key = { 1,6,5,2,4 };
	}
	Accounts::Accounts(char* str)
	{
		name = str;
		money = 0;
		status = true;
		login = false;
		key = { 1,6,5,2,4 };
	}
	Accounts::Accounts(char* str, const ui balance)
	{
		name = str;
		money = balance;
		status = true;
		login = false;
		key = { 1,6,5,2,4 };
	}
	Accounts::Accounts(const ui balance)
	{
		money = balance;
		name = "NoName";
		status = true;
		login = false;
		key = { 1,6,5,2,4 };
	}

	void Accounts::getMoney(ui a)
	{
		if (login == false)
			return;
		money += a;
	}
	void Accounts::Print()
	{
		system("cls");
		char anser;
		switch (login)
		{
		case true:
			std::cout << name << std::endl;
			std::cout << money << std::endl;
			if (status)
				std::cout << "Работоспособен" << std::endl;
			else
				std::cout << "3аблокирован" << std::endl;
			break;
		case false:
			std::cout << "Уважаемый " << name << ", чтобы воспользоватся услугами нашего сервиса, Вам необходимо авторизоватся в системе!" << std::endl;
			std::cout << "Хотите выполнить авторизацию?" << std::endl;
			cin >> anser;
			if (anser == 'y')
			{
				Autorization();
			}
			else return;
		}
		
	}
	void Accounts::Block()
	{
		if (login == false)
			return;
		status = false;
	}
	void Accounts::UnBlock()
	{
		if (login == false)
			return;
		status = true;
	}
	void Accounts::Autorization()
	{
		int arr[5];
		std::cout << "Введите ваш пин код: ";
		for (int i(0); i < 5; i++)
			cin >> arr[i];
		Pin_kode a(arr);
	
		if (a.arr[0] == key.arr[0] && a.arr[1] == key.arr[1] && a.arr[2] == key.arr[2] && a.arr[3] == key.arr[3] && a.arr[4] == key.arr[4])
		{
			std::cout << "Авторизация успешно выполнена!" << std::endl;
			login = true;
			return;
		}
		else
		std::cout << "Неверный пин код!" << std::endl; 
	}
}
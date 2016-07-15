#pragma once

#include<string>

namespace Programm
{
	typedef unsigned int ui;
	using namespace std;

	class Accounts
	{
	private:
		string name;
		int money;
		bool status;
		bool login;
		struct Pin_kode
		{
			size_t arr[5];
			Pin_kode(int a, int b, int c, int d,int e)
			{
				int ar[] = { a,b,c,d,e };
				for (int i(0); i < 5; i++)
					arr[i] = ar[i];
			}
			Pin_kode()
			{
				for (int i(0); i < 5; i++)
					arr[i] = 0;
			}
			Pin_kode(int a[])
			{
				for (int i(0); i < 5; i++)
					arr[i] = a[i];
			}
		};
		Pin_kode key;
	public:
		Accounts();
		Accounts(char*);
		Accounts(char*, const ui);
		Accounts(const ui);
		void getMoney(ui);
		void Print();
		void Block();
		void UnBlock();
		void Autorization();
	};
}

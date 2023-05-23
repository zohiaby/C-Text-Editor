#include<iostream>
#include<conio.h>
#include <windows.h>
#include<fstream>
#include"header.h"
#include<string>
#include<cstdlib>
using namespace std;
int main() 
{
	
	trie_tree obj;
	ofstream out;
	ifstream in;
	fstream file1;
	in.open("Dictionary.txt", ios::in);
	if (!in.is_open())
	{
		cout << "File is not open !!!" << endl;
	}
	else 
	{
		while (!in.eof())
		{
			string ch;
			getline(in, ch);
			obj.insert(ch);
		}
	}
	char user = -1;
	char* arr;
	arr = new char;
	arr[0] = '1';
	int* encodearr,check=0;
	encodearr = new int;
	while (user != 51)
	{
		cout << "Press 1 to write\n";
		cout << "Press 2 to see your file data\n";
		cout << "Press 3 for exit\n";
		cout << "Press Key : ";
		user = _getch();
		switch (user) 
		{
		case 49:
			for (int i = 0;; i++)
			{
				if (i == 0)
				{
					system("cls");
					cout << "Write in notepad to save data press 1\n";
				}
				user=_getch();
				if (user == '1')
				{
					system("cls");
					break;
				}
				if (user != 1)
				{
					obj.sugg(user);
					cout << "Suggested words are\n";
					char select = 0;
					int suggword = 0;
					do
					{
						system("cls");
						cout << "Select your word by ; or next word /\n";
						cout << "------  -----  ------  ----- -----" << endl;
						obj.displaywords(suggword);
						cout << "Press / or ; ";
						select = _getch();
						if (select == '/')
						{
							suggword++;
							if (suggword >= 10)
								suggword = 0;
						}
						system("cls");
					} while (select != ';');
					cout << "Write in notepad to save data press 1";
					obj.writeandprintonnotepad(arr, suggword);
				}
				check = 1;
				for (int i = 0;; i++)
				{
					if (arr[i] == '1')
					{
						encodearr[i] = 49;
						break;
					}
					if (arr[i] == 32)
					{
						encodearr[i] = 32;
						continue;;
					}
					int num = arr[i] - 97;
					for (int j = 0; j < 26; j++)
					{
						if (num == j)
						{
							encodearr[i] = j;
							break;
						}
					}
				}
			}
			break;
		case 48:
			break;
		case 50:
			if (check == 1)
			{
				for (int i = 0;; i++)
				{
					if (encodearr[i] == 49)
					{
						arr[i] = '1';
						break;
					}
					if (encodearr[i] == 32)
					{
						arr[i] = ' ';
						continue;
					}
					for (int j = 0; j < 26; j++)
					{
						if (encodearr[i] == j)
						{
							arr[i] = encodearr[i] + 97;
							break;
						}
					}
				}
			}
			
			do
			{
				system("cls");
				file1.open("new.txt", ios::in);
				string a;
				cout << "Here is File Data :" << endl;
				cout << "---- ---- ---- ----" << endl;
				while (!file1.eof())
				{
					file1>>a;
					cout << a <<" ";
				}
				file1.close();
				cout << "\n\nPress b for main menu :";
				user = _getch();
			} while (user != 'b');
			cout << endl;
			system("cls");
			break;
		}
	}
	in.close();
	return 0;
}
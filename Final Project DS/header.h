#include<iostream>
#include<conio.h>
#include <windows.h>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
struct node
{
	char data;
	node* child[26];
	bool check;
	bool finalword;
	node()
	{
		data = 0;
		check = false;
		finalword = false;
		for (int i = 0; i < 26; i++)
		{
			child[i] = NULL;
		}
	}
};
class trie_tree
{
	node* root;
	node* insert2(node* temp, char dat);
	void suggested(node* temp, string dat);
	int generatehashvalue(char dat);
public:
	fstream file;

	string* arr;
	int counter = 0;
	trie_tree();
	~trie_tree();
	void insert(string dat);
	void makenull(node* temp);
	void sugg2(node* temp, char dat, int j);
	void sugg(char dat);
	void displaywords(int suggword);
	void writeandprintonnotepad(char* arr1, int suggarr);
};
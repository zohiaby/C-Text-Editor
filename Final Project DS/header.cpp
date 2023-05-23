#include "header.h"
node* trie_tree::insert2(node* temp, char dat)
{
	node* newnode = new node();
	newnode->data = dat;
	return newnode;

}

void trie_tree::suggested(node* temp, string dat)
{
	dat += temp->data;
	if (temp->finalword == true)
	{
		if (counter == 10)
		{
			return;
		}
		arr[counter] = dat;
		counter++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (temp->child[i] != NULL)
		{
			suggested(temp->child[i], dat);
		}
	}
}

int trie_tree::generatehashvalue(char dat)
{
	return (dat + 7) % 26;
}

trie_tree::trie_tree()
{
	root = NULL;
	arr = new string[10];
}

trie_tree::~trie_tree()
{
	delete root;
}

void trie_tree::insert(string dat)
{

	if (root == NULL)
	{
		node* newnode = new node();
		newnode->data = '-';
		root = newnode;
	}
	node* curr = root;
	for (int i = 0;; i++)
	{
		if (dat[i] == '\0')
		{
			break;
		}
		int num = generatehashvalue(dat[i]);

		node* newnode = new node();
		newnode->data = dat[i];
		newnode->check = true;
		int nume = i;
		nume = nume + 1;
		if (dat[nume] == '\0')
		{
			newnode->finalword = true;
		}
		bool check2 = false;
		if (curr->child[num] != NULL)
		{
			check2 = curr->child[num]->check;
		}
		if (check2 == false)
		{
			curr->child[num] = newnode;
		}
		//makenull(curr->child[num]);
		curr = curr->child[num];
	}
}

void trie_tree::makenull(node* temp)
{
	for (int i = 0; i < 26; i++)
	{
		temp->child[i] = NULL;
	}
}

void trie_tree::sugg2(node* temp, char dat, int j)
{
	counter = 0;
	for (int i = 0; i < 26; i++)
	{
		if (temp->child[i] != NULL)
		{
			if (temp->child[i]->data == dat)
			{
				string str;
				suggested(temp->child[i], str);
			}
		}
	}
}

void trie_tree::sugg(char dat)
{
	int j = 0;
	sugg2(root, dat, j);
}

void trie_tree::displaywords(int suggword)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	if (suggword != 0)
	{
		for (int i = 0; i < suggword; i++)
		{
			SetConsoleTextAttribute(console_color, 15);
			cout << arr[i] << "  ";
		}
	}
	SetConsoleTextAttribute(console_color, 12);
	cout << arr[suggword] << "  ";
	if (suggword != 10)
	{
		for (int i = suggword + 1; i < 10; i++)
		{
			SetConsoleTextAttribute(console_color, 15);
			cout << arr[i] << "  ";
		}
	}
	SetConsoleTextAttribute(console_color, 15);
	cout << endl;
}

void trie_tree::writeandprintonnotepad(char* arr1, int suggarr)
{
	cout << endl;
	file.open("new.txt", ios::app);
	string word = arr[suggarr];
	file << word << " ";
	file.close();
	int j = 0;
	for (int i = 0;; i++)
	{
		if (arr1[i] != '1')
		{
			continue;
		}
		else
		{
			if (word[j] != NULL)
			{
				arr1[i] = word[j];
				arr1[i + 1] = '1';
				j++;
			}
			else
			{
				arr1[i] = ' ';
				arr1[1 + i] = '1';
				break;
			}
		}
	}
	for (int i = 0;; i++)
	{
		if (arr1[i] == '1')
		{
			break;
		}
		cout << arr1[i];
	}
}

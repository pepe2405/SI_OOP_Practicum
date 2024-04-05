#include <iostream>
using namespace std;
const int n = 15;
struct link { char key; link* next; } *gr[n];

void init(link * gr[n]);
int search_node(link* gr[n], char c);
int search_arc(link* gr[5], char c1, char c2);
void add_node(link* gr[n], char c);
void add_arc(link* gr[n], char c1, char c2);
void del_node(link* gr[n], char c);
void del_arc(link* gr[n], char c1, char c2);
void list_node(link* gr[n]);

void init(link* gr[n])
{
	for (int i = 0; i < n; i++)
		gr[i] = NULL;

}
int search_node(link* gr[n], char c)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
		if (gr[i])
			if (gr[i]->key == c)
			{
				flag = 1;
				break;
			}
	return flag;
}
int search_arc(link* gr[5], char c1, char c2)
{
	int flag = 0;
	if (search_node(gr, c1) && search_node(gr, c2))
	{
		int i = 0;
		while (gr[i]->key != c1) i++;
		link* p = gr[i];
		if (p) {
			while (p->key != c2 && p->next != NULL)
				p = p->next;
			if (p->key == c2)
				flag = 1;
		}
	}
	return flag;
}
void add_node(link* gr[n], char c)
{
	if (search_node(gr, c))
		cout << "\nExisting node!\n";
	else
	{
		int j = 0;
		while (gr[j] && (j < n))
			j++;
		if (gr[j] == NULL)
		{
			gr[j] = new link;
			gr[j]->key = c;
			gr[j]->next = NULL;
		}
		else
			cout << "\nOverflow!\n";

		СИНТЕЗ И АНАЛИЗ НА АЛГОРИТМИ

			4

	}
}
void add_arc(link* gr[n], char c1, char c2)
{
	int i = 0;
	link* p;
	if (search_arc(gr, c1, c2))
	{
		cout << "\nExisting arc!";
	}
	else
	{
		if (!(search_node(gr, c1)))
			add_node(gr, c1);
		if (!(search_node(gr, c2)))
			add_node(gr, c2);
		while (gr[i]->key != c1)
			i++;
		p = new link;
		p->key = c2;
		p->next = gr[i]->next;
		gr[i]->next = p;
	}
}
void del_node(link* gr[n], char c)
{
	if (search_node(gr, c))
	{
		int i = 0;
		while (gr[i]->key != c)
			i++;
		link* p, * q = NULL;
		while (gr[i] != NULL)
		{
			p = gr[i];
			gr[i] = p->next;
			delete p;
		}
		for (i = 0; i < n; i++)
			if (gr[i])
			{
				p = gr[i];
				while ((p->key != c) && (p->next != NULL))
				{
					q = p;
					p = p->next;
				}
				if (p->key == c)
				{
					q->next = p->next;
					delete p;
				}
			}

	}
	else
		cout << "The node is not in the graph!";

}
void del_arc(link* gr[n], char c1, char c2)
{
	if (search_arc(gr, c1, c2))
	{
		int i = 0;
		while (gr[i]->key != c1)
			i++;
		link* p = gr[i], * q = NULL;
		while (p->key != c2)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
	else
		cout << "\nThe arc is not in the graph!";

}
void list_node(link* gr[n]) //Print Graph
{
	cout << "\n";
	for (int i = 0; i < n; i++)
		if (gr[i])
			cout << gr[i]->key;

}
int main()
{
	setlocale(LC_ALL, "bg");
	char c, k;
	int m;
	do
	{
		cout << "\n\n Main menu\n\n";
		cout << "1 - Init\n";
		cout << "2 - Add node\n";
		cout << "3 - Add arc\n";
		cout << "4 - Delete Node\n";
		cout << "5 - Delete Arc\n";
		cout << "6 - Search Node\n";
		cout << "7 - Search Arc\n";
		cout << "8 - Print All\n";
		cout << "9 - End";
		cout << "\n\nEnter (1-9):";
		cin >> m;
		switch (m)
		{
		case 1:
		{
			init(gr); break;
		}
		case (2):
		{
			cout << "\nEnter node (char): ";
			cin >> c;
			add_node(gr, c);
			break;
		}
		case (3):
		{
			cout << "\nEnter first node (char) :";
			cin >> c;
			cout << "\nEnter second node (char):";
			cin >> k;
				add_arc(gr, c, k);
			break;
		}
		case (4):
		{
			cout << "\nEnter node (char):";
			cin >> c;
			del_node(gr, c);
			break;
		}
		case (5):
		{
			cout << "\nEnter first node (char):";
			cin >> c;
			cout << "\nEnter second node (char):";
			cin >> k;
			del_arc(gr, c, k);
			break;
		}
		case (6):
		{
			cout << "\nEnter node (char): ";
			cin >> k;
			if (search_node(gr, k))
				cout << "\nSearch result: OK!";
			else
				cout << "\nSearch result: NO!";
			break;
		}
		case (7):
		{
			cout << "\nEnter first node (char):";
			cin >> c;
			cout << "\nEnter second node (char):";
			cin >> k;
			if (search_arc(gr, c, k))
				cout << "\nSearch result: OK!";
			else
				cout << "\nSearch result: NO!";
			break;
		}
		case (8):
		{
			list_node(gr); break;
		}
		}
	} while (m != 9);
	cout << "\n";
}
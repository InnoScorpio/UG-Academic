// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

	struct Node {int key; /*string Node;*/ Node *next;};
	Node *l;

	void print(Node *list)
	{
		Node *p; p = list;
		if (list) {
			while (p->next){ cout << p->key << '\t' /*<p->name*/; p = p->next; }
			cout << p->key << endl;
		}
	}

	void insert(int item)
	{

		Node *nod, *q, *p, *t; q = p = l;
		nod = new Node;
		nod->key = item;
		nod->next = 0;

		if (!l) l = nod; //cas-1 if(emptylist) insert the first node
		else if (l->key > item) { nod->next = l; l = nod; } //case2-it inserts the smallest-key-node on top of the list
		else {
			while (p->next && p->key < item) { q = p; p = p->next; } //search
			if (p->next == 0 && p->key < item) p->next = nod; //case3-insert the last node
			else { q->next = nod; nod->next = p; } //case4-insert nod in the middle of the LL
			print(l);
		}
	}

	void remove(int item)
	{
		Node *p, *q; p = q = l;
		if (!l) return;
		else if (p->key == item) { p = l; l = l->next; delete p; } //case2-it inserts the smallest-key-node on top of the list
		else {
			while (p !=0) {   //search
				if (p->key != item) { q = p;  p = p->next; } //case3-insert the last node
				else { q->next = p->next; delete p; break; }
			}//case4-insert nod in the middle of the LL
			print(l);
		}
	}

		void main()
		{
			int item; char s; l = 0;
			while (1)
			{
				cout << "Select: '0' exit, '>' insert, '<' delete, '?' printList" << endl; cin>>s;
				if (s == '0') exit(0);
				else if (s == '>') { cout << "Enter a number to insert\n"; cin >> item; insert(item); }
				else if (s == '<') { cout << "Enter a number to delete\n"; cin >> item; remove(item); }
				else if (s == '?') print(l);
			}
		}

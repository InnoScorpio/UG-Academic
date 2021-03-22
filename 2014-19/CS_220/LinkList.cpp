#include<iostream>
using namespace std;

int key;

struct Node{ 
	int key;
	Node *next;
};

Node *LinkL, *Front, *Rear;

int getKey() { cout << "Enter Key: "; cin >> key; return (key); }


void printList(Node *LinkL)
{
	if (LinkL)
	{

		while (LinkL != NULL)
		{
			cout << LinkL->key << "  ";
			LinkL = LinkL->next;
		}

   }

}

void printQueue(Node *Front)
{
	if (Front)
	{

		while (Front != NULL)
		{
			cout << Front->key << "  ";
			Front = Front->next;
		}

	}

}
void enQueue(int item)
{
	Node *node;
	node = new Node;
	node->key = item; node->next = NULL;
	
	if (Front == NULL && Rear == NULL)
	{
		Front = Rear = node;
		return;
	}
	
	Rear ->next = node;
	Rear = node;

	printQueue(Front);
	cout << endl;
}

void deQueue()
{
	Node *node = Front;
	if (Front == NULL)
	{
		return;
	}

	else if (Front == Rear)
	{
		Front = Rear = NULL;
	}
	
	else
	{
		Front = Front->next;
	}

	delete node;
	
	printQueue(Front);
	cout << endl;
}


void pushStack(int item)
{
	Node *node;
	// Node *p, *q;
	// p = q = LinkL;
	node = new Node;
	node->key = item; node->next = LinkL;
	LinkL = node;

	/*if (!LinkL)
		LinkL = node;
	else if (LinkL->key > item)
	{
		node->next = LinkL; LinkL = node;
	}
	else
	{
		while (p->next && p->key < item)
		{
			q = p;
			p = p->next;
		}
		
		if (p->next == 0 && p->key < item) p->next = node;
		
		else
		{
			q->next = node; node->next = p;
		}
	}*/
	
	printList(LinkL);
	cout << endl;
}

void popStack(/*Node *&LinkL, int item*/)
{
	Node *current;
	// Node *p;
	// p = current = LinkL;

	if (LinkL == NULL)
	{
		return;
	}

	current = LinkL;
	LinkL = LinkL->next;
	delete current;
	
	/*else if (current->key == item)
	{
		p = LinkL;
		LinkL = LinkL->next;
		delete p;

	}
	else
	{
		while (current != NULL)
		{

			if (current->key != item)
			{
				p = current;
				current = current->next;
			}
			else
			{
				p->next = current->next;
				delete current;
				break;
			}
		}
	}*/

	printList(LinkL);
	cout << endl;
}

void menu()
{
	while (1){
		int choice;
		cout << "\nLinked List Menu\n";
		cout << "\n 0: Exit\n 1: pushStack()\n 2: popStack()\n 3: printStack()\n 4: enQueue()\n 5: deQueue()\n 6: printQueue()\n";
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: key = getKey(); pushStack(key); break;
		case 2: /*key = getKey();*/ popStack(/*LinkL, key*/); break;
		case 3: printList(LinkL); break;
		case 4: key = getKey(); enQueue(key); break;
		case 5: deQueue(); break;
		case 6: printQueue(Front); break;
		}
	}
}

int main()
{
	LinkL = NULL;
	Front = NULL;
	Rear = NULL;
	menu();

	return 0;
}
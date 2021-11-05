//REVERSING THE LINKED LIST

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
    { 
        head = NULL; 
    }

	void reverse()
	{
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};
int count = 1 ;
void reverseUtil(Node* curr, Node* prev, Node** head);

void reverse(Node** head)
{
	if (!head)
		return;
	reverseUtil(*head, NULL, head);
}

void reverseUtil(Node* curr, Node* prev, Node** head)
{
	if (!curr->next) {
		*head = curr;
		curr->next = prev;
		return;
	}
	Node* next = curr->next;
	curr->next = prev;
	reverseUtil(next, curr, head);
}

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printlist(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head1 = newNode(85);
	head1->next = newNode(15);
	head1->next->next = newNode(40);
	head1->next->next->next = newNode(20);

	cout << "Given linked list\n";
	printlist(head1);
	reverse(&head1);
	cout << "\nReversed linked list\n";
	printlist(head1);
	return 0;
}

*/

/*
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

void reverseLL(Node **head)
{
	stack<Node *> s;
	Node *temp = *head;
	while (temp->next != NULL)
	{
		s.push(temp);
		temp = temp->next;
	}
	*head = temp;

	while (!s.empty())
	{
		temp->next = s.top();
		s.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

void printlist(Node *temp)
{
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insert_back(Node **head, int value)
{
	Node *temp = new Node();
	temp->data = value;
	temp->next = NULL;

	if (*head == NULL)
	{
		*head = temp;
		return;
	}
	else
	{
		Node *last_node = *head;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = temp;
		return;
	}
}

int main()
{
	Node *head = NULL;

	insert_back(&head, 1);
	insert_back(&head, 2);
	insert_back(&head, 3);
	insert_back(&head, 4);
	cout << "Given linked list\n";
	printlist(head);
	reverseLL(&head);
	cout << "\nReversed linked list\n";
	printlist(head);
	return 0;
}

*/

/*
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList()
	{
		head = NULL;
	}

	Node* reverse(Node* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		Node* rest = reverse(head->next);
		head->next->next = head;
		
		head->next = NULL;
		return rest;
	}

	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};


int main()
{
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}

*/

/*
INSERTION
    1) At the front of the linked list  
    2) After a given node. 
    3) At the end of the linked list.
    4) Specific position
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

Node* head ;

void push(int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

void insertAfter(Node* prev, int data)
{
	if (prev == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}

	Node* temp = new Node();
	temp->data = data;
	temp->next = prev->next;
	prev->next = temp;
}

void append(int new_data)
{
	Node* new_node = new Node();
	Node *last = head;
	new_node->data = new_data;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void insert_pos(int data , int n)
{
    Node* temp1 = new Node() ;
    temp1->data = data ;
    temp1->next = NULL ;

    if(n==1)
    {
        temp1->next = head ;
        head = temp1 ;
        return ;
    }

    Node* temp2 = head ;

    for(int i = 0 ; i<n-2 ; i++)
    {
        temp2 = temp2->next ;
    }

    temp1->next = temp2->next ;
    temp2->next = temp1 ;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main()
{
	head = NULL ;

	append(6); 
	push(7); 
	push(1); 
	append(4);
	insertAfter(head->next, 8);
	insertAfter(head->next->next, 10);
    insert_pos(20,1);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;

	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	insertAfter(head->next->next, 10);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}

*/
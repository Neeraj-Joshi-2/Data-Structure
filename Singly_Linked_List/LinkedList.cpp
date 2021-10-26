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

void delete_Pos(int pos)
{
    Node *temp1 = head;
    if (pos == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void deleteNode(Node* local_head, int key)
{
    Node* temp = local_head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        head = temp->next; 
        delete temp;            
        return;
    }

      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    delete temp;
    }
}

bool search(int x) 
{ 
    Node* current = head;  
    while (current != NULL) 
    { 
        if (current->data == x) 
            return true; 
        current = current->next; 
    } 
    return false; 
}


int main()
{
	head = NULL;

	append(6); 
	push(7); 
	push(1); 
	append(4);
	insertAfter(head->next, 8);
	insertAfter(head->next->next, 10);
    insert_pos(20,1);

	cout<<"Created Linked list is: ";
	printList(head);

	delete_Pos(6) ;

	cout<<"\nCreated Linked list is: ";
	printList(head);

    search(1)? cout<<"\nYes" : cout<<"\nNo";
	
	return 0;
}
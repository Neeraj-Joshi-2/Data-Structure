//SEARCHING 


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

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
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

bool search2(Node* head, int x) 
{
    if (head == NULL) 
        return false; 

    if (head->data == x) 
        return true; 

    return search2(head->next, x); 
}

int main()
{
	head = NULL;

	push(7); 
	push(1); 
	push(4); 
	push(6); 

	cout<<"Created Linked list is: ";
	printList(head);

    search(5)? cout<<"\nYes" : cout<<"\nNo";
    search2(head , 5)? cout<<"\nYes" : cout<<"\nNo";
	
	return 0;
}


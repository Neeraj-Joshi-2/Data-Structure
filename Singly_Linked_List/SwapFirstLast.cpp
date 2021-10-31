//SWAPPING THE FIRST AND LAST ELEMENT


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

void swapElement()
{
    Node *temp = head , *head_next = head->next , *last_prev = head , *head_ref = head;
    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    while(last_prev->next->next != NULL)
    {
        last_prev = last_prev->next ;
    }
    head = temp ;
    temp->next = head_next ;
    last_prev->next = head_ref ;
    head_ref->next = NULL ;
}

int main()
{
	head = NULL;

	push(7); 
	push(1); 
	push(6); 
	push(3); 
	push(8); 

	cout<<"Created Linked list is : ";
	printList(head);

    swapElement() ;

    cout<<"\nAfter operation : ";
	printList(head);

	
	return 0;
}


//MOVING LAST ELEMENT TO FIRST

//FUNCTION

/*
void moveToFront(Node **head_ref) 
{ 

    if (*head_ref == NULL || (*head_ref)->next == NULL) 
        return; 

    Node *secLast = NULL; 
    Node *last = *head_ref; 

    while (last->next != NULL) 
    { 
        secLast = last; 
        last = last->next; 
    } 
    secLast->next = NULL; 
    last->next = *head_ref; 
    *head_ref = last; 
} 
*/

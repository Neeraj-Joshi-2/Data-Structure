//DELETION

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

int main()
{
	head = NULL;

	push(7); 
	push(1); 
	push(6); 
	push(3); 
	push(8); 

	cout<<"Created Linked list is: ";
	printList(head);

	delete_Pos(1) ;
    deleteNode(head , 3) ;

	cout<<"\nCreated Linked list is: ";
	printList(head);
	
	return 0;
}

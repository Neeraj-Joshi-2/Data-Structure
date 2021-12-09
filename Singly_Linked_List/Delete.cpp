// DELETING THE LINKED LIST

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
    if(node==NULL)
    {
        cout<<"List is empty" ;
        return ;
    }
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

void deleteList()
{
	Node* current = head;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}
 
int main()
{
	head = NULL ;
	push(7); 
	push(1); 
	push(2); 
	push(3); 

	cout<<"Created Linked list is: ";
	printList(head);

    deleteList();

    cout<<"\nLinked list is: ";
	printList(head);
	
	return 0;
}

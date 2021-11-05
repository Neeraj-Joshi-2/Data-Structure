//ARRANGING IN SEQUENCE -> EVEN FIRST THEN ODD , MAINTAINING THE ORDER OF NODES

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

void segregateEvenOdd(Node **head_ref)
{
	Node *end = *head_ref;
	Node *prev = NULL;
	Node *curr = *head_ref;

	while (end->next != NULL)
		end = end->next;

	Node *new_end = end;

	while (curr->data % 2 != 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	if (curr->data%2 == 0)
	{
		*head_ref = curr;

		while (curr != end)
		{
			if ( (curr->data) % 2 == 0 )
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				prev->next = curr->next;
				curr->next = NULL;
				new_end->next = curr;
				new_end = curr;
				curr = prev->next;
			}
		}
	}

	else prev = curr;

	if (new_end != end && (end->data) % 2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data <<" ";
		node = node->next;
	}
}

int main()
{
	Node* head = NULL;

	push(&head, 11);
	push(&head, 6);
	push(&head, 9);
	push(&head, 3);
	push(&head, 4);
	push(&head, 2);
	push(&head, 7);
	push(&head, 5);
	

	cout << "Original Linked list ";
	printList(head);

	segregateEvenOdd(&head);

	cout << "\nModified Linked list ";
	printList(head);

	return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void segregateEvenOdd(struct Node **head_ref)
{
	Node *evenStart = NULL;
	Node *evenEnd = NULL;
	Node *oddStart = NULL;
	Node *oddEnd = NULL;
	
	Node *currNode = *head_ref;
	
	while(currNode != NULL){
		int val = currNode -> data;

		if(val % 2 == 0) {
			if(evenStart == NULL){
				evenStart = currNode;
				evenEnd = evenStart;
			}
			
			else{
				evenEnd -> next = currNode;
				evenEnd = evenEnd -> next;
			}
		}
		
		else{
			if(oddStart == NULL){
				oddStart = currNode;
				oddEnd = oddStart;
			}
			else{
				oddEnd -> next = currNode;
				oddEnd = oddEnd -> next;
			}
		}
		currNode = currNode -> next;	
	}
	
	if(oddStart == NULL || evenStart == NULL){
		return;
	}
	
	evenEnd -> next = oddStart;
	oddEnd -> next = NULL;
	
	*head_ref = evenStart;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *node)
{
	while (node!=NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 11);
	push(&head, 10);
	push(&head, 9);
	push(&head, 6);
	push(&head, 4);
	push(&head, 1);
	push(&head, 0);

	printf("\nOriginal Linked list \n");
	printList(head);

	segregateEvenOdd(&head);

	printf("\nModified Linked list \n");
	printList(head);

	return 0;
}

*/

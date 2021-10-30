// SWAPPING THE NODES NOT THE DATA

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void swapNodes(struct Node** head_ref, int x, int y)
{
	if (x == y)
		return;

	struct Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	struct Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}

	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else 
		*head_ref = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else
		*head_ref = currX;

	struct Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* start = NULL;

	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("\n Linked list before calling swapNodes() ");
	printList(start);

	swapNodes(&start, 4, 3);

	printf("\n Linked list after calling swapNodes() ");
	printList(start);

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std ;

struct Node {
	int data;
	struct Node* next;
};

struct Node* start ;

void swapNodes(int x, int y)
{
	if (x == y)
		return;

	struct Node *prevX = NULL, *currX = start;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	struct Node *prevY = NULL, *currY = start;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}

	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else 
		start = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else 
		start = currX;

	struct Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

void push(int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = start ;
	start = new_node ;
}

void printList()
{
    Node* node = start ;
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	start = NULL;

	push(7);
	push(6);
	push(5);
	push(4);
	push(3);
	push(2);
	push(1);

    cout<<"\n"<<start<<"\n" ;

	printf("\n Linked list before calling swapNodes() ");
	printList();

	swapNodes(6, 1);

	printf("\n Linked list after calling swapNodes() ");
	printList();

    cout<<"\n\n"<<start<<"\n" ;

	return 0;
}

*/

/*

#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    class Node *next;

    Node(int val, Node *next) : data(val), next(next)
    {
    }

    void printList()
    {
        Node *node = this;

        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }
};

void push(Node **head_ref, int new_data)
{
    (*head_ref) = new Node(new_data, *head_ref);
}

void swap(Node *&a, Node *&b)
{
    Node *temp = a;
    a = b;
    b = temp;
}

void swapNodes(Node **head_ref, int x, int y)
{
    if (x == y)
        return;

    Node **a = NULL, **b = NULL;

    while (*head_ref)
    {

        if ((*head_ref)->data == x)
        {
            a = head_ref;
        }

        else if ((*head_ref)->data == y)
        {
            b = head_ref;
        }

        head_ref = &((*head_ref)->next);
    }

    if (a && b)
    {
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}

int main()
{
    Node *start = NULL;

    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before calling swapNodes() ";
    start->printList();

    swapNodes(&start, 6, 1);

    cout << "Linked list after calling swapNodes() ";
    start->printList();
}

*/

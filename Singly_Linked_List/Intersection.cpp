//INTERSECTION

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head = NULL ;
void push(Node** head_ref, int new_data);

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

Node* sortedIntersect(Node* a, Node* b)
{
	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			append(a->data);
			a = a->next;
			b = b->next;
		}

		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return head ;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

int main()
{
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedIntersect(a, b);

	cout<<"Linked list containing common items of a & b \n";
	printList(intersect);
}

/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* sortedIntersect(struct Node* a,struct Node* b)
{
	if (a == NULL || b == NULL)
		return NULL;

	if (a->data < b->data)
		return sortedIntersect(a->next, b);

	if (a->data > b->data)
		return sortedIntersect(a, b->next);

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = a->data;
	temp->next = sortedIntersect(a->next, b->next);
	return temp;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
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
	struct Node* a = NULL;
	struct Node* b = NULL;
	struct Node* intersect = NULL;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedIntersect(a, b);

	printf("\n Linked list containing common items of a & b \n ");
	printList(intersect);

	return 0;
}

*/

/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *(head_ref);
    *(head_ref) = new_node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

void intersection(Node *head1, Node *head2)
{
    Node *head3 = NULL;
    Node *temp1 = head1;
    
    while (temp1 != NULL)
    {
        Node *temp2 = head2;
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                push(&head3, temp1->data);
                temp2 = temp2->next;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    cout << "\nll 3  : ";
    printList(head3);
}

int main()
{
    Node *head1, *head2;
    head1 = NULL, head2 = NULL;

    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 6);
    push(&head1, 6);

    push(&head2, 4);
    push(&head2, 2);
    push(&head2, 6);

    

    cout << "ll 1  : ";
    printList(head1);
    cout << "\nll 2  : ";
    printList(head2);

    intersection(head1 , head2) ;

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data);

struct Node *sortedIntersect(struct Node *a,struct Node *b)
{
    struct Node *result = NULL;
    struct Node **lastPtrRef = &result;

    while (a != NULL && b != NULL)
    {
        if (a->data == b->data)
        {
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (result);
}

void push(struct Node **head_ref,int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *a = NULL;
    struct Node *b = NULL;
    struct Node *intersect = NULL;

    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    intersect = sortedIntersect(a, b);

    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);

    getchar();
}

*/

/*
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data);

Node* sortedIntersect(Node* a, Node* b)
{
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;

	while (a != NULL && b != NULL) {
		if (a->data == b->data) {
			push((&tail->next), a->data);
			tail = tail->next;
			a = a->next;
			b = b->next;
		}

		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return (dummy.next);
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data <<" ";
		node = node->next;
	}
}

int main()
{
	Node* a = NULL;
	Node* b = NULL;
	Node* intersect = NULL;

	push(&a, 6);
	push(&a, 5);
	push(&a, 4);
	push(&a, 3);
	push(&a, 2);
	push(&a, 1);

	push(&b, 8);
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);

	intersect = sortedIntersect(a, b);

	cout<<"Linked list containing common items of a & b \n";
	printList(intersect);
}

*/

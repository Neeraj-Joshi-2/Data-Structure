//FINDING MIDDLE ELEMENT

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    for (int i = 3; i > 0; i--)
    {
        push(&head, i);
        printList(head);
    }
    printMiddle(head);


    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printMiddle(struct node* head)
{
	int count = 0;
	struct node* mid = head;

	while (head != NULL)
	{
		if (count & 1)
			mid = mid->next;

		++count;
		head = head->next;
	}

	if (mid != NULL)
		printf("The middle element is [%d]\n\n",
				mid->data);
}

void push(struct node** head_ref, int new_data)
{

	struct node* new_node = (struct node*)malloc(
		sizeof(struct node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct node* ptr)
{
	while (ptr != NULL)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

int main()
{

	struct node* head = NULL;
	int i;

	for(i = 5; i > 0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddle(head);
	}
	return 0;
}



*/
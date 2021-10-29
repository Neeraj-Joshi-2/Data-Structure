// FINDING LOOP AND COUNTING THE NUMBER OF NODES IN IT 

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
int countNodes(struct Node *n)
{
	int res = 1;
	struct Node *temp = n;
	while (temp->next != n)
	{
		res++;
		temp = temp->next;
	}
	return res;
}
bool detectLoop(struct Node* h)
{
	unordered_set<Node*> s;
	while (h != NULL) {

		if (s.find(h) != s.end())
        {
            cout<<"\n"<<h->data<<"\n";
            int o = countNodes(h);
            cout<<o ;
			return true;

        }
		s.insert(h);
		h = h->next;
	}

	return false;
}

int main()
{
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);
	push(&head, 1);

	head->next->next->next->next->next = head->next;

	if (detectLoop(head))
		cout << "\nLoop found";
	else
		cout << "\nNo Loop";

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

int countNodes(struct Node *n)
{
	int res = 1;
	struct Node *temp = n;
	while (temp->next != n)
	{
		res++;
		temp = temp->next;
	}
	return res;
}

int countNodesinLoop(struct Node *list)
{
	struct Node *slow_p = list, *fast_p = list;

	while (slow_p && fast_p &&
					fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		if (slow_p == fast_p)
			return countNodes(slow_p);
	}

	return 0;
}

struct Node *newNode(int key)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

int main()
{
	struct Node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	head->next->next->next->next->next = head->next;

	cout << countNodesinLoop(head) << endl;

	return 0;
}
*/
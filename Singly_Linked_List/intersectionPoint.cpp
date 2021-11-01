//INTERSECTION POINT OF TWO LINKED LIST

/*
    USING TWO FOR LOOPS
    USING DIFFERENCE OF NODES COUNTS  **1
    HASHING                           **2
    TWO POINTERS TECHNIQUE            **3
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

int getCount(Node* head);
int _getIntesectionNode(int d, Node* head1, Node* head2);

int getIntesectionNode(Node* head1, Node* head2)
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if (c1 > c2) {
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else {
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}
}

int _getIntesectionNode(int d, Node* head1, Node* head2)
{
	Node* current1 = head1;
	Node* current2 = head2;

	for (int i = 0; i < d; i++) {
		if (current1 == NULL) {
			return -1;                           
		}
		current1 = current1->next;
	}

	while (current1 != NULL && current2 != NULL) {
		if (current1 == current2)
			return current1->data;
		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

int getCount(Node* head)
{
	Node* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	/*
		Create two linked lists
	
		1st 3->6->9->15->30
		2nd 10->15->30
	
		15 is the intersection point
	*/

	Node* newNode;

	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}


/*
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class LinkedListIntersection {
    public static void main(String[] args) {

        Node n1 = new Node(1);
        n1.next = new Node(2);
        n1.next.next = new Node(3);
        n1.next.next.next = new Node(4);
        n1.next.next.next.next = new Node(5);
        n1.next.next.next.next.next = new Node(6);
        n1.next.next.next.next.next.next = new Node(7);

        Node n2 = new Node(10);
        n2.next = new Node(9);
        n2.next.next = new Node(8);
        n2.next.next.next = n1.next.next.next;
        Print(n1);
        Print(n2);
        System.out.println(MegeNode(n1,n2).data);
    }

    public static void Print(Node n) {
        Node cur = n;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
        System.out.println();
    }

    public static Node MegeNode(Node n1, Node n2) {
        HashSet<Node> hs = new HashSet<Node>();
        while (n1 != null) {
            hs.add(n1);
            n1 = n1.next;
        }
        while (n2 != null) {
            if (hs.contains(n2)) {
                return n2;
            }
            n2 = n2.next;
        }
        return null;
    }
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* intersectPoint(Node* head1, Node* head2)
{
	Node* ptr1 = head1;
	Node* ptr2 = head2;

	if (ptr1 == NULL || ptr2 == NULL) {

		return NULL;
	}
	while (ptr1 != ptr2) {

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;

		if (ptr1 == ptr2) {

			return ptr1;
		}
		if (ptr1 == NULL) {

			ptr1 = head2;
		}
		if (ptr2 == NULL) {

			ptr2 = head1;
		}
	}

	return ptr1;
}

void print(Node* node)
{
	if (node == NULL)
		cout << "NULL";
	while (node->next != NULL) {
		cout << node->data << "->";
		node = node->next;
	}
	cout << node->data;
}

int main()
{
	Node* newNode;
	Node* head1 = new Node();
	head1->data = 10;
	Node* head2 = new Node();
	head2->data = 3;
	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;
	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;
	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;
	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;
	head1->next->next->next = NULL;

	Node* intersect_node = NULL;


	intersect_node = intersectPoint(head1, head2);

	cout << "INTERSEPOINT LIST :";

	print(intersect_node);

	return 0;

}

*/

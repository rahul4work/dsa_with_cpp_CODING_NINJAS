/*
SWAP TWO NODES OF LINKED LIST
level: moderate

Problem statement
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions and return the new head 
to the list.

Note :
1. Remember, You need to swap the nodes, not only the data.
2. Indexing starts from 0.
3. No need to print the list, it has already been taken care.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec


---------------------------------------------------------------------------------------------
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
---------------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------------
Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
---------------------------------------------------------------------------------------------
*/



#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
	if (i == j) {
        return head;
    }

    Node* prevNode1 = NULL, *currNode1 = head;
    Node* prevNode2 = NULL, *currNode2 = head;

    // Find the nodes at index i and j
    int pos = 0;
    while (currNode1 != NULL && pos != i) {
        prevNode1 = currNode1;
        currNode1 = currNode1->next;
        pos++;
    }

    pos = 0;
    while (currNode2 != NULL && pos != j) {
        prevNode2 = currNode2;
        currNode2 = currNode2->next;
        pos++;
    }

    // If either of the nodes wasn't found, return the head
    if (currNode1 == NULL || currNode2 == NULL) {
        return head;
    }

    // If one of the nodes is the head
    if (prevNode1 != NULL) {
        prevNode1->next = currNode2;
    } else {
        head = currNode2;
    }

    if (prevNode2 != NULL) {
        prevNode2->next = currNode1;
    } else {
        head = currNode1;
    }

    // Swap next pointers
    Node* temp = currNode1->next;
    currNode1->next = currNode2->next;
    currNode2->next = temp;

    return head;
}




Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
  

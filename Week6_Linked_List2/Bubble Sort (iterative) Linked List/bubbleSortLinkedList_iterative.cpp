/*
BUBBLE SORT (ITERATIVE) LINKED LIST
level: moderate

Problem statement
Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec


------------------------------------------------------------------------------------------------
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------------------------
 Sample Input 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
------------------------------------------------------------------------------------------------
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

Node *bubbleSort(Node *head)
{
	// Write your code here
	if (head == NULL || head->next == NULL) {
        return head;
    }

    bool swapped;
    Node *temp;
    Node *prev = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != prev) {
            if (temp->data > temp->next->data) {
                // Swap the data of temp and temp->next
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
        prev = temp; // Move prev to the last swapped node
    } while (swapped);

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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}

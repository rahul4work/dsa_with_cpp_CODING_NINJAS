/*
EVEN AFTER ODD LINKED LIST
level: moderate

Problem statement
For a given singly linked list of integers, arrange the nodes such that all the even
number nodes are placed after the all odd number nodes. The relative order of the odd 
and even terms should remain unchanged.

  
Note :
1. No need to print the linked list, it has already been taken care. Only return the new 
head to the list.
2. Don't create a new linked list.
3.  Just change the data, instead rearrange the provided list.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

  
Time Limit: 1sec



------------------------------------------------------------------------------------------
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
------------------------------------------------------------------------------------------


  
------------------------------------------------------------------------------------------
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
------------------------------------------------------------------------------------------
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

Node *evenAfterOdd(Node *head)
{
	//write your code here

	if (head == NULL) {
        return head;
    }
    
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    
    Node* current = head;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {  // Even node
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {  // Odd node
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }
    
    // If there are no odd nodes, return evenHead
    if (oddHead == NULL) {
        return evenHead;
    }
    
    // Combine odd and even lists
    oddTail->next = evenHead;
    
    // Ensure the last node of even list points to NULL
    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
    
    return oddHead;
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
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}




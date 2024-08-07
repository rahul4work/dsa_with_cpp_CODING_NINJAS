/*
MIDPOINT OF LINKED LIST

Problem statement
For a given singly linked list of integers, find and return the node present at 
the middle of the list.

Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present 
at the middle with respective data values are, 20 and 30. We return the first node 
with data 20.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5 
Where M is the size of the singly linked list.


Time Limit: 1sec


----------------------------------------------------------------------------------
Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
3
----------------------------------------------------------------------------------


----------------------------------------------------------------------------------
Sample Input 2 :
2 
-1
1 2 3 4 -1
Sample Output 2 :
2
----------------------------------------------------------------------------------
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

Node *midPoint(Node *head)
{
    // Write your code here
	if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}



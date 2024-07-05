/*
FIND A NODE IN LINKED LIST

Problem statement
You have been given a singly linked list of integers. Write a function that returns 
the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.

Note :
Assume that the Indexing for the singly linked list always starts from 0.


Constraints :
1 <= T <= 10^2
0 <= M <= 10^5

Where 'M' is the size of the singly linked list.

Time Limit: 1 sec


---------------------------------------------------------------------------------------------
Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
Sample Output 1 :
2
-1
---------------------------------------------------------------------------------------------


---------------------------------------------------------------------------------------------
Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6
Sample Output 2 :
-1
4
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

int findNode(Node *head, int n){
    // Write your code here.
     int pos = 0;
    while (head != NULL) {
        if (head->data == n)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}



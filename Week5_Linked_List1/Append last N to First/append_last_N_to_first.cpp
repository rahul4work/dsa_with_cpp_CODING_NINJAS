/*
APPEND LAST N TO FIRST

Problem statement
You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the singly 
linked list and returns the new head to the list.

Hint:
Identify how many pointers you require and try traversing them to right places 
and connect nodes accordingly also don't forget to disconnect what's required 
else it could create cycles.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec


Where 'M' is the size of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly
linked list and hence, would never be a list element.



--------------------------------------------------------------------------------
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
--------------------------------------------------------------------------------


--------------------------------------------------------------------------------
Sample Input 2 :
1
10 6 77 90 61 67 100 -1
4
Sample Output 2 :
90 61 67 100 10 6 77 
--------------------------------------------------------------------------------
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

Node *appendLastNToFirst(Node *head, int n)
{

	if (head == NULL || n == 0) 
        return head;
    
    int length = 0;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        length++;
    }
    length++; 
    

    if (n >= length)
        return head;
    

    int targetIndex = length - n;
    Node* prev = NULL;
    Node* curr = head;
    for (int i = 0; i < targetIndex; ++i) {
        prev = curr;
        curr = curr->next;
    }
    

    temp->next = head;
    head = curr;
    prev->next = NULL;
    
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
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}


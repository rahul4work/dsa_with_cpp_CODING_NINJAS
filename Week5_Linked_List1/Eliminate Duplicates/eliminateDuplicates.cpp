/*
ELIMINATE DUPLICATES

Problem statement
You have been given a singly linked list of integers where the elements are sorted in ascending order. 
Write a function that removes the consecutive duplicate values such that the given list only contains 
unique elements and returns the head to the updated list.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, 
would never be a list element.



-------------------------------------------------------------------------------------------------------
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
-------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------
Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10
-------------------------------------------------------------------------------------------------------
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

Node *removeDuplicates(Node *head)
{
    //Write your code here
	if (head == NULL)
        return NULL;
    
    Node* current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {

            current = current->next;
        }
    }
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}



10 20 30 40 50
10

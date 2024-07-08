/*
PALINDROME DOUBLY LINKED LIST

Problem statement
You have been given a head to a doubly linked list of integers. Write a function 
check to whether the list given is a 'Palindrome' or not.

Note:
There is no requirement for input or output handling. Your task is to implement a 
function that returns whether the given doubly linked list is a palindrome or not. 
The nodes in the doubly linked list are connected to its previous nodes using a 'prev'
pointer in addition to the usual next pointer.



Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the doubly linked list.



---------------------------------------------------------------------------------------
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
---------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
---------------------------------------------------------------------------------------
*/



#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data)
	{
		
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};


bool palindromeDLL(Node* head){

	if (!head) return true; 

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) {
            return false; 
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
    
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
			newNode->prev = tail;
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
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}




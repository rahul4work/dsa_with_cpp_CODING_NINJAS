/*
PALINDROME LINKED LIST

Problem statement
You have been given a head to a singly linked list of integers. Write a function check 
to whether the list given is a 'Palindrome' or not.


Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.


--------------------------------------------------------------------------------------
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
--------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
--------------------------------------------------------------------------------------
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

bool isPalindrome(Node *head)
{
    //Write your code here
	if (head == NULL || head->next == NULL) 
        return true;
    
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    Node *nextNode = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }
   
    if (fast != NULL)
        slow = slow->next;
    
    Node *p1 = prev; 
    Node *p2 = slow; 
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data)
            return false;
        
        p1 = p1->next;
        p2 = p2->next;
    }
    
    slow = prev;
    prev = NULL;
    while (slow != NULL) {
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }
    head = prev;
    
    return true;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}



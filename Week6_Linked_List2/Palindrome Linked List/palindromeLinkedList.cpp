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
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Function to get the length of the linked list
    auto length = [](Node* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    };

    // Function to reverse the linked list in place
    auto reverseInPlace = [](Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    };

    int len = length(head);

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list in place
    Node* prev = NULL;
    Node* curr = slow->next;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    slow->next = prev;

    // Compare the first half and the reversed second half
    Node* firstHalf = head;
    Node* secondHalf = prev;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            // Restore the original list by reversing the second half back
            Node* temp = NULL;
            while (prev != NULL) {
                Node* next = prev->next;
                prev->next = temp;
                temp = prev;
                prev = next;
            }
            slow->next = temp;
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Restore the original list by reversing the second half back
    Node* temp = NULL;
    while (prev != NULL) {
        Node* next = prev->next;
        prev->next = temp;
        temp = prev;
        prev = next;
    }
    slow->next = temp;

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



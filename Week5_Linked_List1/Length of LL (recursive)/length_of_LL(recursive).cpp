/*
LENGTH OF LL (RECURSIVE)
  
Problem statement
Given a linked list, find and return the length of the given linked list recursively.

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
1 <= t <= 20
0 <= N <= 10^4
  
Time Limit: 1 sec


--------------------------------------------------------------------------------------
Sample Input 1:
1 
3 4 5 2 6 1 9 -1
Sample Output 1:
7
--------------------------------------------------------------------------------------
*/


#include <iostream>
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;


int length(Node *head) {
    // Write your code here
	if (head == NULL)
        return 0;
    return 1 + length(head->next);
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}



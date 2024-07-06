/*
REVERSE LL (ITERATIVE)

Problem statement
Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.


--------------------------------------------------------------------------------------------------------
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
--------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
--------------------------------------------------------------------------------------------------------
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

Node *reverseLinkedList(Node *head) {
    // Write your code here
	Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev; 
        prev = current; 
        current = next;
    }

    return prev;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
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

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}



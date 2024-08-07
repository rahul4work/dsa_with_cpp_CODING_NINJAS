/*
NEXT NUMBER

Problem statement
Given a large number represented in the form of a linked list. Write code to 
increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements and return 
the head of updated LL. Input Constraints:
1 <= Length of Linked List <=10^6.



---------------------------------------------------------------------------------
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
---------------------------------------------------------------------------------


---------------------------------------------------------------------------------
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
---------------------------------------------------------------------------------
*/



#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;


Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head == nullptr)
        return head;

    Node* current = head;
    Node* lastNonNine = nullptr;

    while(current->next != nullptr) {
        if (current->data != 9)
            lastNonNine = current;
        current = current->next;
    }
    if (current->data != 9) {
        current->data += 1;
    }else if (lastNonNine == nullptr) {
        Node* newHead = new Node(1);
        newHead->next = head;
        head = newHead;
        current = head;
    }else {
        lastNonNine->data += 1;
        current = lastNonNine-> next;
        while (current != nullptr) {
            current->data = 0;
            current = current->next;
        }
    }
    return head;

    
}


Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}






  

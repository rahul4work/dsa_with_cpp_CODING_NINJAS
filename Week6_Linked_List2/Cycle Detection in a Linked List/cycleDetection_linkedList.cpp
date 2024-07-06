/*
CYCLE DETECTION IN A SINGLY LINKED LIST
level: moderate

Problem statement
You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.

A cycle occurs when a node's next points back to a previous node in the list.



------------------------------------------------------------------------------------------------
Sample Input 1 :
1 2 3 4 -1
1
Sample Output 1 :
true
------------------------------------------------------------------------------------------------


  
------------------------------------------------------------------------------------------------
Sample Input 2 :
1 2 3 4 -1
0
Sample Output 2 :
true
------------------------------------------------------------------------------------------------
*/


#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

bool detectCycle(Node *head)
{
	//	Write your code here
     if (!head || !head->next) {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

class Runner
{
    int t;
    vector<Node *> arr;

public:
    Node *takeInput()
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

        int pos;
        cin >> pos;

        if (pos != -1)
        {

            Node *temp = head;
            //  Connecting last element to "pos"th node
            while (pos--)
            {
                temp = temp->next;
            }
            tail->next = temp;
        }

        return head;
    }

    void execute(Node *head)
    {
        bool ans = detectCycle(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        bool ans = detectCycle(head);
        if (ans)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Runner runner;
    Node *head = runner.takeInput();
    runner.executeAndPrintOutput(head);

    return 0;
}



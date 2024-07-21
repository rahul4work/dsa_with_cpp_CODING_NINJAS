/*
ROTATE LINKED LIST
level: moderate

Problem statement
You are given a linked list having ‘n’ nodes and an integer ‘k’.

You have to rotate the linked list to the right by ‘k’ positions .

Example :
Input: linked list = [1 2 3 4] , k = 2

Output: 3 4 1 2

Explanation:
We have to rotate the given linked list to the right 2 times. After rotating it to the right
once it becomes 4->1->2->3. After rotating it to the right again, it becomes 3->4->1->2. 


Constraints :
1 <= n <= 10^5
0 <= Node.data <= 10^9 
0 <= k <= 10^5

Time Limit: 1 sec


-----------------------------------------------------------------------------------------------
Sample Input 1 :
6
1 2 3 4 5 6
2
Sample Output 1 :
5 6 1 2 3 4
-----------------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------------
Sample Input 2 :
3
3 6 9 
0
Sample Output 2:
3 6 9
-----------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k) {
     // Write your code here.
     if (!head || k == 0) {
        return head;
    }

    // Step 1: Determine the length of the linked list
    Node* current = head;
    int length = 1;
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Step 2: Optimize k
    k = k % length;
    if (k == 0) {
        return head;
    }

    // Step 3: Make the list circular
    current->next = head;

    // Step 4: Find the new tail (node at position length - k)
    int stepsToNewHead = length - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 5: Adjust the pointers
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

class Runner
{
    int k;
    vector<int> list;

public:
    void takeLLInput(int n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            list.push_back(x);
        }
    }

    void printLL(Node *head)
    {

        while (head)
        {
            Node *temp = head;
            cout << head->data << ' ';
            head = head->next;
            delete temp;
        }
    }
    void takeInput()
    {
        int n;
        cin>>n;
        takeLLInput(n);
        cin >> k;
    }

    void execute()
    {
        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void executeAndPrintOutput()
    {

        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        printLL(ans);
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}



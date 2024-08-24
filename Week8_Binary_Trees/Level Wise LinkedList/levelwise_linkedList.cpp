/*
LEVEL WISE LINKED LIST

Problem statement
Given a binary tree, write code to create a separate linked list for each level. You need to return 
the array which contains head of each level linked list.


Constraints:
Time Limit: 1 second


---------------------------------------------------------------------------------------------------
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
---------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<Node<int>*> result;
    if (root == nullptr) {
        return result;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node<int>* head = nullptr;
        Node<int>* tail = nullptr;

        for (int i = 0; i < levelSize; ++i) {
            BinaryTreeNode<int>* current = q.front();
            q.pop();

            Node<int>* newNode = new Node<int>(current->data);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }


        result.push_back(head);
    }

    return result;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}




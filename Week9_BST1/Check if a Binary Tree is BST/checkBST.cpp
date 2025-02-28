/*
Check BST
level: moderate

Problem statement
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.

Note:
Duplicate elements should be kept in the right subtree.


Constraints :
0 <= Number of edges <= 10^5
Time Limit: 1 second

--------------------------------------------------------------------------------------------------------------------------------------------------
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :
true
--------------------------------------------------------------------------------------------------------------------------------------------------



--------------------------------------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :
false
--------------------------------------------------------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

#include <climits>

bool isBSTUtil(BinaryTreeNode<int>* node, int min, int max) {

    if (node == NULL) {
        return true;
    }

    if (node->data < min || node->data > max) {
        return false;
    }

    return
        isBSTUtil(node->left, min, node->data - 1) && 
        isBSTUtil(node->right, node->data, max); 
}

bool isBST(BinaryTreeNode<int> *root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}




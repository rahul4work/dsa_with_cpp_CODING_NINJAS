/*
CHECK BALANCED
level : moderate

Problem statement
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, 
following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    


Constraints
Time Limit: 1 second


------------------------------------------------------------------------------------------------------------------
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
------------------------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
------------------------------------------------------------------------------------------------------------------
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

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if (root == NULL) {
        return true;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    bool leftBalanced = isBalanced(root->left);
    bool rightBalanced = isBalanced(root->right);
    
    if (leftBalanced && rightBalanced && std::abs(leftHeight - rightHeight) <= 1) {
        return true;
    }
    
    return false;
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
    cout << (isBalanced(root) ? "true" : "false");
}


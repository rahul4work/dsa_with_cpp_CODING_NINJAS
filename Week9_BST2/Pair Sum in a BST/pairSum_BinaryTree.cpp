/*
PAIR SUM IN BINARY TREE
level: moderate

Problem statement
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:

1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Constraints:
Time Limit: 1 sec
1 ≤ Number of Nodes ≤ 10^5
1 ≤ S ≤ 10^6


---------------------------------------------------------------------------------------
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15

Sample Output 1:
5 10
6 9
---------------------------------------------------------------------------------------
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

#include <stack>

void inorderPushLeft(std::stack<BinaryTreeNode<int>*>& stack, BinaryTreeNode<int>* root) {
    while (root != nullptr) {
        stack.push(root);
        root = root->left;
    }
}

void inorderPushRight(std::stack<BinaryTreeNode<int>*>& stack, BinaryTreeNode<int>* root) {
    while (root != nullptr) {
        stack.push(root);
        root = root->right;
    }
}

void pairSum(BinaryTreeNode<int>* root, int sum) {
    if (root == nullptr) {
        return;
    }

    std::stack<BinaryTreeNode<int>*> leftStack;
    std::stack<BinaryTreeNode<int>*> rightStack;

    // Initialize leftStack with inorder traversal (smallest to largest)
    inorderPushLeft(leftStack, root);

    // Initialize rightStack with reverse inorder traversal (largest to smallest)
    inorderPushRight(rightStack, root);

    // Two pointers to track nodes
    BinaryTreeNode<int>* currentLeft = leftStack.top();
    BinaryTreeNode<int>* currentRight = rightStack.top();

    while (currentLeft->data < currentRight->data) {
        int currentSum = currentLeft->data + currentRight->data;

        if (currentSum == sum) {
            std::cout << currentLeft->data << " " << currentRight->data << std::endl;
            // Move left to the next node in inorder traversal
            leftStack.pop();
            if (currentLeft->right != nullptr) {
                currentLeft = currentLeft->right;
                inorderPushLeft(leftStack, currentLeft);
            } else {
                currentLeft = leftStack.top();
            }
            // Move right to the next node in reverse inorder traversal
            rightStack.pop();
            if (currentRight->left != nullptr) {
                currentRight = currentRight->left;
                inorderPushRight(rightStack, currentRight);
            } else {
                currentRight = rightStack.top();
            }
        } else if (currentSum < sum) {
            // Move left to the next node in inorder traversal
            leftStack.pop();
            if (currentLeft->right != nullptr) {
                currentLeft = currentLeft->right;
                inorderPushLeft(leftStack, currentLeft);
            } else {
                currentLeft = leftStack.top();
            }
        } else { // currentSum > sum
            // Move right to the next node in reverse inorder traversal
            rightStack.pop();
            if (currentRight->left != nullptr) {
                currentRight = currentRight->left;
                inorderPushRight(rightStack, currentRight);
            } else {
                currentRight = rightStack.top();
            }
        }
    }
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}



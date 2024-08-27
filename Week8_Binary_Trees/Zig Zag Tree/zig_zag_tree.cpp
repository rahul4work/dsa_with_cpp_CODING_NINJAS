/*
ZIG ZAG TREE

Problem statement
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right,
level 2 from right to left and so on. This means odd levels should get printed from left to right and
even level right to left.


Constraints
Time Limit: 1 second


------------------------------------------------------------------------------------------------------
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
------------------------------------------------------------------------------------------------------
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
	if (root == nullptr) {
        return;
    }

    std::deque<BinaryTreeNode<int>*> q;
    q.push_back(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        if (leftToRight) {
            for (int i = 0; i < levelSize; ++i) {
                BinaryTreeNode<int>* current = q.front();
                q.pop_front();
                std::cout << current->data << " ";

                if (current->left != nullptr) {
                    q.push_back(current->left);
                }
                if (current->right != nullptr) {
                    q.push_back(current->right);
                }
            }
        } else {
            for (int i = 0; i < levelSize; ++i) {
                BinaryTreeNode<int>* current = q.back();
                q.pop_back();
                std::cout << current->data << " ";

                if (current->right != nullptr) {
                    q.push_front(current->right);
                }
                if (current->left != nullptr) {
                    q.push_front(current->left);
                }
            }
        }

        leftToRight = !leftToRight;
        std::cout << std::endl;
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
    zigZagOrder(root);
}



/*
FIND PATH IN BST
level: moderate

Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and root 
(if a node with data k is present in given BST) in a list. Return empty list otherwise.

Note: Assume that BST contains all unique elements.


Constraints:
Time Limit: 1 second   



-------------------------------------------------------------------------------------
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2

Sample Output 1:
2 5 8
-------------------------------------------------------------------------------------
*/


#include <iostream>
#include <queue>

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
#include <vector>

#include <vector>

bool findPath(BinaryTreeNode<int>* root, int data, std::vector<int>& path) {
    if (root == nullptr) {
        return false;
    }

    if (findPath(root->left, data, path)) {
        path.push_back(root->data);
        return true;
    }

    if (root->data == data) {
        path.push_back(root->data);
        return true;
    }


    if (findPath(root->right, data, path)) {
        path.push_back(root->data);
        return true;
    }

    return false;
}

std::vector<int>* getPath(BinaryTreeNode<int>* root, int data) {
    std::vector<int>* path = new std::vector<int>();
    findPath(root, data, *path);
    return path;
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

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}



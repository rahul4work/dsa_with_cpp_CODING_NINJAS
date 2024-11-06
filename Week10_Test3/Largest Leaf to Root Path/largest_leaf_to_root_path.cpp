/*
LARGEST LEAF TO ROOT PATH
level: moderate

Problem statement
Given a binary tree, return the longest path from leaf to root. 
Longest means, a path which contain maximum number of nodes from 
leaf to root.


-----------------------------------------------------------------
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
9
3
6
5
-----------------------------------------------------------------
*/



#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

#include <algorithm>

vector<int>* longestPathHelper(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return new vector<int>();
    }

    vector<int>* leftPath = longestPathHelper(root->left);
    vector<int>* rightPath = longestPathHelper(root->right);

    if(leftPath->size() > rightPath->size()) {
        leftPath->push_back(root->data);
        return leftPath;
    }
    else{
        rightPath->push_back(root->data);
        return rightPath;
    }
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    vector<int>* result = longestPathHelper(root);
    
    std::reverse(result->begin(), result->end());
    return result;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}



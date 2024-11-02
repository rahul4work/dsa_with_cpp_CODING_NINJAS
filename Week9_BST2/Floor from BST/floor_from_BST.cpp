/*
FLOOR FROM BST

Problem statement
Given a binary search tree and an integer.Find the floor value of a key in a binary search tree .

(If k lies in BST then is floor equal to k,else floor is equal to previous greater value) 
Note: k would never be less than the minimum element of tree.


------------------------------------------------------------------------------------------------
Sample Input 1:
4
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2
------------------------------------------------------------------------------------------------



------------------------------------------------------------------------------------------------
Sample Input 2:
7
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 2:
7
------------------------------------------------------------------------------------------------
*/


#include <iostream>
#include <queue>
#include <limits.h>
#include<unordered_set>

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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;


int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 

    int floorValue = INT_MIN; 

    while (node != nullptr) {
        if (node->data == input) {
            return node->data; 
        } else if (node->data > input) {
            node = node->left; 
        } else {
            floorValue = node->data; 
            node = node->right; 
        }
    }

    return floorValue;

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
	int x;
    cin>>x;
    BinaryTreeNode<int>* root1 = takeInput();
    
    cout<<Floor(root1,x);
   
        delete root1;

    return 0;
}




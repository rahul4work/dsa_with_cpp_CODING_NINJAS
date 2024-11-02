/*
Kth SMALLEST NODE IN BST
level: moderate

Problem statement
Given a BST and an integer K, you need to find the Kth smallest element present in the BST. 
Return INT_MIN if that is not present in the BST.


-------------------------------------------------------------------------------------------
Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
3
Sample Output :
6
-------------------------------------------------------------------------------------------
*/


#include <iostream>
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

    ~BinaryTreeNode() {
    	if(left) 
    	    delete left;
    	if(right) 
    	    delete right;
    }
};

using namespace std;

#include <iostream>
#include <stack>
#include <climits>


int findNode(BinaryTreeNode<int>* root, int k) {
    if (root == nullptr || k <= 0) {
        return INT_MIN;
    }
    
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int>* current = root;
    int count = 0;
    
    while (current != nullptr || !st.empty()) {

        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        
        current = st.top();
        st.pop();
        count++;
        
        if (count == k) {
            return current->data;
        }
        
        current = current->right;
    }
    

    return INT_MIN;
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
    int k;
    cin >> k;
    cout << findNode(root, k);
    delete root;
}






  

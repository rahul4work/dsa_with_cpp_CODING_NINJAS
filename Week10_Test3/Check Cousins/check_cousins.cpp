/*
CHECK COUSINS

Problem statement
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are 
cousins of each other or not. Two nodes are said to be cousins of each other if they are 
at same level of the Binary Tree and have different parents.

Do it in O(n).


Constraints :
1 <= N <= 10^5


-----------------------------------------------------------------------------------------
Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true
-----------------------------------------------------------------------------------------
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
};

using namespace std;

#include <utility>

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    if(!root) return false;

    std::queue<std::pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>> nodeQueue;;
    nodeQueue.push({root, nullptr});

    BinaryTreeNode<int> *parentP = nullptr, *parentR = nullptr;
    int levelP = -1, levelR = -1;
    int level = 0;

    while(!nodeQueue.empty()) {
        int size = nodeQueue.size();
        for(int i = 0; i<size; ++i) {
            auto frontPair = nodeQueue.front();
            BinaryTreeNode<int>* node = frontPair.first;
            BinaryTreeNode<int>* parent = frontPair.second;
            nodeQueue.pop();

            if(node->data == p) {
                parentP = parent;
                levelP = level;
            }
            if(node->data == nodeQueue) {
                parentR = parent;
                levelR = level;
            }
            if (parentP && parentR) {
                return (levelP == levelR) && (parentP != parentR);
            }

            if (node->left) nodeQueue.push({node->left, node});
            if (node->right) nodeQueue.push({node->right, node});
        }
        ++level;
    }

    return false;
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}




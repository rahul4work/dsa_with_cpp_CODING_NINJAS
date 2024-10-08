/*
LEVEL ORDER TRAVERSAL

Problem statement
For a given a Binary Tree of type integer, print it in a level order fashion where each 
level will be printed on a new line. Elements on every level will be printed in a linear 
fashion and a single space will separate them.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec


-----------------------------------------------------------------------------------------
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
Sample Output 1:
10 
20 30 
40 50 60 
-----------------------------------------------------------------------------------------


-----------------------------------------------------------------------------------------
Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 
-----------------------------------------------------------------------------------------
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

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
	if (root == NULL) {
        return;
    }

    std::queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelCount = q.size(); 
        while (currentLevelCount > 0) {
            BinaryTreeNode<int>* currentNode = q.front();
            q.pop();
            std::cout << currentNode->data << " ";
            
            if (currentNode->left != NULL) {
                q.push(currentNode->left);
            }
         
            if (currentNode->right != NULL) {
                q.push(currentNode->right);
            }
            
            currentLevelCount--;
        }
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
    printLevelWise(root);
}



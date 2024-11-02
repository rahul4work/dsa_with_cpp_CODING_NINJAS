/*
LARGEST BST
level: hard

Problem statement
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with
maximum height in the given binary tree. You have to return the height of largest BST.

Note :
The binary tree will be consisting of only unique elements.


Constraints:
1 ≤ Number of nodes ≤ 10^5
1 ≤ Data of a node ≤ 10^6
Time Limit: 1 second


-------------------------------------------------------------------------------------------
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1:
2
-------------------------------------------------------------------------------------------
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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


#include <climits>

class Info {
public:
    bool isBST;
    int size;
    int minVal;
    int maxVal;
    int height;

    Info(bool isBST, int size, int minVal, int maxVal, int height) {
        this->isBST = isBST;
        this->size = size;
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->height = height;
    }
};


Info largestBSTHelper(BinaryTreeNode<int>* root, int &maxHeight) {
    if (!root) {
        return Info(true, 0, INT_MAX, INT_MIN, 0);
    }

    Info leftInfo = largestBSTHelper(root->left, maxHeight);
    Info rightInfo = largestBSTHelper(root->right, maxHeight);

    bool isBST = leftInfo.isBST && rightInfo.isBST &&
                 (root->data > leftInfo.maxVal) && (root->data < rightInfo.minVal);

    if (isBST) {
        int size = 1 + leftInfo.size + rightInfo.size;
        int height = 1 + max(leftInfo.height, rightInfo.height);
        maxHeight = max(maxHeight, height);
        int minVal = min(root->data, leftInfo.minVal);
        int maxVal = max(root->data, rightInfo.maxVal);
        return Info(true, size, minVal, maxVal, height);
    } else {
        return Info(false, 0, 0, 0, 0);
    }
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    int maxHeight = 0;
    largestBSTHelper(root, maxHeight);
    return maxHeight;
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
    cout << largestBSTSubtree(root);
    delete root;
}



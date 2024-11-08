/*
PAIR SUM ROOF TO LEAF 
level: hard

Problem statement
For a given Binary Tree of type integer and a number K, print out all root-to-leaf
paths where the sum of all the node data along the path is equal to K.

Example:
If you see in the above-depicted picture of Binary Tree, we see that there are a 
total of two paths, starting from the root and ending at the leaves which sum up 
to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference 
to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)



-------------------------------------------------------------------------------------
Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
Sample Output 1:
2 3 4 4 
2 3 8
-------------------------------------------------------------------------------------



-------------------------------------------------------------------------------------
Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
Sample Output 2:
5 6 2
5 7 1
-------------------------------------------------------------------------------------
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


#include <vector>

template <typename T>
void rootToLeafPathsSumToKHelper(BinaryTreeNode<T>* root, int k, vector<T>& path) {
    if (root == NULL) {
        return;
    }

    path.push_back(root->data);

    if (root->left == NULL && root->right == NULL) {
        int sum = 0;
        for (T val : path) {
            sum += val;
        }
        if (sum == k) {
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i] << " ";
            }
            cout << endl;
        }
    } else {

        rootToLeafPathsSumToKHelper(root->left, k, path);
        rootToLeafPathsSumToKHelper(root->right, k, path);
    }


    path.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int>* root, int k) {
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, k, path);
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
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}



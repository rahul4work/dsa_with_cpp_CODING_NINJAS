/*
DELETE NODE IN BST

Problem statement
You have been given a Binary Search Tree of integers with ‘N’ nodes. You are also given data of 
a node of this tree. Your task is to delete the given node from the BST.


A binary search tree (BST) is a binary tree data structure that has the following properties:

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.


Constraints:
1 <= N <=5000
0<= data <=10^5
Where ‘N’ is the number of nodes in the binary search tree and ‘data' denotes data contained in
the node of the binary search tree.

Time limit: 1 sec



---------------------------------------------------------------------------------------------------
Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12 15 16 20 25 
---------------------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------------------
Sample Input 2:
6 4 -1 -1 5
6
Sample output 2:
4 5
---------------------------------------------------------------------------------------------------
*/



#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>


template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

using namespace std;

BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    else {

        if (root->left == NULL) {
            BinaryTreeNode<int>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            BinaryTreeNode<int>* temp = root->left;
            delete root;
            return temp;
        }

        BinaryTreeNode<int>* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


class Runner
{
    int t = 1;

    vector<BinaryTreeNode<int>* > arr;
    vector<int> keys;

public:

    void takeInput()
    {

        // cin >> t;

        for (int c = 0; c < t; c++)
        {
            int rootData;
            cin >> rootData;

            if (rootData == -1)
            {
                arr.push_back(NULL);
                continue;
            }

            BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

            queue<BinaryTreeNode<int> *> q;

            q.push(root);

            while (!q.empty())
            {
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
                    BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
                    currentNode->right = rightNode;
                    q.push(rightNode);
                }
            }
            arr.push_back(root);

            int key;

            cin >> key;

            keys.push_back(key);
        }

    }

    void printInorder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        printInorder(root -> left);

        cout << root -> data << " ";

        printInorder(root -> right);
    }

    BinaryTreeNode<int> *copyTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BinaryTreeNode<int> *copyRoot = new BinaryTreeNode<int>(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode<int> *copy = copyTree(arr[i]);

            copy = deleteNode(copy, keys[i]);

            delete copy;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode<int> *root = arr[i];
            root = deleteNode(root, keys[i]);

            if (root == NULL)
            {
                cout << -1;
            }
            else
            {
                printInorder(root);
            }

            cout << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}




  

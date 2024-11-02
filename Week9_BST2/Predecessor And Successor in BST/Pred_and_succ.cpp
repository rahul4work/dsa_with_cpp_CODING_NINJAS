/*
PREDECESSOR AND SUCCESSOR IN BST

Problem statement
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' 
which represents data of a node of this tree.


Your task is to return the predecessor and successor of the given node in the BST.


Note:
1. The predecessor of a node in BST is that node that will be visited just before the given node 
in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, 
then its predecessor is NULL.

2. The successor of a node in BST is that node that will be visited immediately after the given node 
in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then 
its successor is NULL.

3. The node for which the predecessor and successor will not always be present. If not present, you can 
hypothetically assume it's position (Given that it is a BST) and accordingly find out the predecessor and successor.

4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.


Constraint :
1 <= N <= 10^4
1 <= data <= 10^7

Time Limit: 1 sec

  
-----------------------------------------------------------------------------------------------------------------------
Sample Input 1:
15 10 20 8 12 16 25 -1 -1 -1 -1 -1 -1 -1 -1
10
Sample output 1:
8 12
-----------------------------------------------------------------------------------------------------------------------
Sample Input 2:
10 5 -1 -1 -1
5
Sample output 2:
-1 10
-----------------------------------------------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <bits/stdc++.h>

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

using namespace std;

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    pair<int, int> result;
    TreeNode *current = root;
    TreeNode *predecessor = nullptr;
    TreeNode *successor = nullptr;

    while (current != nullptr) {
        if (current->data == key) {
    
            if (current->left != nullptr) {
            
                predecessor = current->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
            }
            if (current->right != nullptr) {
            
                successor = current->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
            }
            break; 
        } else if (current->data > key) {
        
            successor = current; 
            current = current->left;
        } else {
            
            predecessor = current; 
            current = current->right;
        }
    }


    if (predecessor) result.first = predecessor->data;
    else result.first = -1;
    if (successor) result.second = successor->data;
    else result.second = -1;

    return result;
}



class Runner
{
    int t;

    vector<TreeNode *> arr;
    vector<int> keys;

public:
    void takeInput()
    {

        t = 1;

        for (int c = 0; c < t; c++)
        {
            int rootData;
            cin >> rootData;

            if (rootData == -1)
            {
                arr.push_back(NULL);
            }

            TreeNode *root = new TreeNode(rootData);

            queue<TreeNode *> q;

            q.push(root);

            while (!q.empty())
            {
                TreeNode *currentNode = q.front();
                q.pop();
                int leftChild, rightChild;

                cin >> leftChild;

                if (leftChild != -1)
                {
                    TreeNode *leftNode = new TreeNode(leftChild);
                    currentNode->left = leftNode;
                    q.push(leftNode);
                }

                cin >> rightChild;
                if (rightChild != -1)
                {
                    TreeNode *rightNode = new TreeNode(rightChild);
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

    TreeNode *copyTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode *copyRoot = new TreeNode(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            TreeNode *copy = copyTree(arr[i]);

            pair<int, int> ans = predecessorSuccessor(copy, keys[i]);

            delete copy;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            TreeNode *root = arr[i];

            pair<int, int> ans = predecessorSuccessor(root, keys[i]);

            cout << ans.first << " " << ans.second << endl;
        }
    }
};

int main()
{
    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}


  

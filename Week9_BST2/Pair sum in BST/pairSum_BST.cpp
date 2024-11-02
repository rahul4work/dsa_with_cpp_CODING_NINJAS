/*
PAIR SUM IN BST

Problem statement
You are given a Binary Search Tree (BST) and a target value ‘K’. Your task is to return true if there 
exist two nodes in the given BST such that the sum of their values is equal to the given target ‘K’, else return false.



A binary search tree (BST) is a binary tree data structure which has the following properties.

• The left subtree of a node contains only nodes with data less than the node’s data.

• The right subtree of a node contains only nodes with data greater than the node’s data.

• Both the left and right subtrees must also be binary search trees.


Note:
1. All the elements of the Binary Search Tree are unique.

2. You can’t use the same node value/element of BST twice.



Constraints:
1 <= 'N' <= 10^5
1 <= DATA <= 10^6
1 <= 'K' <= 10^6


--------------------------------------------------------------------------------------------------------------------------
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
19
Sample Output 1:
false
Explanation for sample input 1:
There are no two elements in the given BST such that their sum equals the given target ‘K’ = 19.
--------------------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------------------------
Sample Input 2 :
20 16 -1 12 -1 8 -1 4 -1 -1 -1 
12
Sample Output 2:
true
--------------------------------------------------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(BinaryTreeNode* root, vector<int>& nodes) {
    if (root == nullptr) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->data);
    inorderTraversal(root->right, nodes);
}

bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Write your code here
    vector<int> nodes;
    inorderTraversal(root, nodes);
    
    int left = 0;
    int right = nodes.size() - 1;
    
    while (left < right) {
        int sum = nodes[left] + nodes[right];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }
    
    return false;
}


class Runner
{
    int t;

    vector<BinaryTreeNode *> arr;

    vector<int> k;

public:
    void takeInput()
    {
        t = 1;

        for (int c = 0; c < t; c++)
        {
            int kVal;

            int rootData;
            cin >> rootData;

            if (rootData == -1)
            {
                arr.push_back(NULL);
            }

            BinaryTreeNode *root = new BinaryTreeNode(rootData);

            queue<BinaryTreeNode *> q;

            q.push(root);

            while (!q.empty())
            {
                BinaryTreeNode *currentNode = q.front();
                q.pop();
                int leftChild, rightChild;

                cin >> leftChild;

                if (leftChild != -1)
                {
                    BinaryTreeNode *leftNode = new BinaryTreeNode(leftChild);
                    currentNode->left = leftNode;
                    q.push(leftNode);
                }

                cin >> rightChild;
                if (rightChild != -1)
                {
                    BinaryTreeNode *rightNode = new BinaryTreeNode(rightChild);
                    currentNode->right = rightNode;
                    q.push(rightNode);
                }
            }
            arr.push_back(root);

            cin >> kVal;
            k.push_back(kVal);
        }
    }

    BinaryTreeNode *copyTree(BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BinaryTreeNode *copyRoot = new BinaryTreeNode(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode *copy = copyTree(arr[i]);
            int kVal = k[i];

            bool ans = pairSumBst(copy, kVal);

            delete copy;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode *root = arr[i];
            int kVal = k[i];

            bool ans = pairSumBst(root, kVal);

            if (ans == 0)
                cout << "false\n";
            else
                cout << "true\n";
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




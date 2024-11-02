/*
CONSTRUCT BST FROM PREORDER
level: moderate

Problem statement
You are given a preorder traversal of a binary search tree. Your task is to find the postorder from the preorder.


Return the root of the BST constructed from the given preorder. The driver code will then use this root to print the post-order traversal.

Constraints:
 1 <= N <= 10^5
 1 <= preorder[i] <= 10^6

Time Limit: 1 sec.
  

--------------------------------------------------------------------------------------------------------------------------------------------
Sample Input 1
6
8 5 1 7 10 12
Sample Output 1:
1 7 5 12 10 8 
--------------------------------------------------------------------------------------------------------------------------------------------



--------------------------------------------------------------------------------------------------------------------------------------------
Sample Input 2:
3
1 3 2
Sample Output 2:
2 3 1 
--------------------------------------------------------------------------------------------------------------------------------------------
*/



#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

#include <stack>

TreeNode* preOrderTree(vector<int>& preOrder) {
    if (preOrder.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preOrder[0]);
    stack<TreeNode*> st;
    st.push(root);

    for (int i = 1; i < preOrder.size(); ++i) {
        TreeNode* temp = nullptr;

        while (!st.empty() && preOrder[i] > st.top()->data) {
            temp = st.top();
            st.pop();
        }

        if (temp != nullptr) {
            temp->right = new TreeNode(preOrder[i]);
            st.push(temp->right);
        }

        else {
            st.top()->left = new TreeNode(preOrder[i]);
            st.push(st.top()->left);
        }
    }

    return root;
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


class Runner
{
    int t;
    vector<vector<int>> arr;

public:
    void takeInput()
    {
        t = 1;
        arr.resize(t);

        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;

            arr[i].resize(n);

            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void postorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left);

        postorder(root->right);

        cout << root->data << " ";
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;

        for (int i = 0; i < t; i++)
        {
            TreeNode *root = preOrderTree(arrCopy[i]);

            delete root;
        }
        arrCopy.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {

            TreeNode *root = preOrderTree(arr[i]);

            postorder(root);
            cout << "\n";
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

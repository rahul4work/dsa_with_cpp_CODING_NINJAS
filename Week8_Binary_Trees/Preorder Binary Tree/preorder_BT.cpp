/*
PREORDER BINARY TREE

Problem statement
You are given a ‘Binary Tree’.


Return the preorder traversal of the Binary Tree.


-------------------------------------------------
Sample Input 1:
1 2 3 5 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:
1 2 5 4 3 6 7
-------------------------------------------------


-------------------------------------------------
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:
5 6 2 3 9 10
-------------------------------------------------


Constraints:
1 <= n <= 100000
where 'n' is the number of nodes in the binary tree.

Time Limit: 1 sec

*/


#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~TreeNode()
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}
};


vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    TreeNode<int>* current = root;
    while (current != nullptr) {
        result.push_back(current->data);

        if (current->left != nullptr) {
            current = current->left;
        } else if (current->right != nullptr) {
            current = current->right;
        } else {
            // Backtrack to find the next node to visit
            while (current->parent != nullptr &&
                   (current == current->parent->right || current->parent->right == nullptr)) {
                current = current->parent;
            }

            if (current->parent != nullptr) {
                current = current->parent->right;
            } else {
                current = nullptr;
            }
        }
    }

    return result;
}

class Runner
{
	int t;
	vector<TreeNode<int> *> allTrees;

	TreeNode<int> *takeTreeInput()
	{

		int rootData;
		cin >> rootData;

		if (rootData == -1)
		{
			return NULL;
		}

		TreeNode<int> *root = new TreeNode<int>(rootData);

		queue<TreeNode<int> *> q;
		q.push(root);

		while (q.empty() == false)
		{
			TreeNode<int> *currentNode = q.front();
			q.pop();
			int leftChild, rightChild;

			cin >> leftChild;

			if (leftChild != -1)
			{
				TreeNode<int> *leftNode = new TreeNode<int>(leftChild);

				currentNode->left = leftNode;
				q.push(leftNode);
			}

			cin >> rightChild;

			if (rightChild != -1)
			{
				TreeNode<int> *rightNode = new TreeNode<int>(rightChild);

				currentNode->right = rightNode;
				q.push(rightNode);
			}
		}

		return root;
	}

	TreeNode<int> *copyTree(TreeNode<int> *root)
	{
		if (root == NULL)
		{
			return NULL;
		}
		TreeNode<int> *copyRoot = new TreeNode<int>(root->data);
		copyRoot->left = copyTree(root->left);
		copyRoot->right = copyTree(root->right);
		return copyRoot;
	}

public:
	void takeInput()
	{
		t = 1;
		allTrees.resize(t);

		for (int i = 0; i < t; i++)
		{
			allTrees[i] = takeTreeInput();
		}
	}

	void execute()
	{
		for (int i = 0; i < t; i++)
		{
			TreeNode<int> *copyRoot = copyTree(allTrees[i]);

			vector<int> ans = preOrder(copyRoot);

			delete copyRoot;
		}
	}

	void executeAndPrintOutput()
	{
		for (int i = 0; i < t; i++)
		{

			vector<int> ans = preOrder(allTrees[i]);
			for (auto i : ans)
				cout << i << " ";
			cout << '\n';
		}
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	// freopen("testcases/large/in/input11.txt", "r", stdin);
	// freopen("output11.txt", "w", stdout);
#endif
	Runner runner;
	runner.takeInput();
	runner.executeAndPrintOutput();
	return 0;
}





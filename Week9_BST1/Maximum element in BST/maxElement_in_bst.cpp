/*
MAXIMUM ELEMENT IN BST

Problem statement
You are given a Binary Search Tree.

Find the minimum value in it.

Note:
All the values in the given binary search tree are unique.

Example:
Input : 6 4 7 2 5 N N

Output: 2

-------------------------------------------------------------
Sample Input 1:
8 5 N 3 6

Sample Output 1:
3   
-------------------------------------------------------------

Explanation of sample output 1:
BST for the given input looks like following:
    8
   / 
  5
 / \
3   6 
Thus the minimum value in this BST is ‘3’.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <sstream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int minVal(Node* root){
	// Write your code here.
	if (root == NULL) {
        return -1; 
    }

    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;	
}

class Runner
{
    string s;

    Node *buildTree(string s)
    {
        if (s.length() == 0 || s[0] == 'N')
            return NULL;

        vector<string> inp;
        istringstream STR(s);
        string cur;
        while (STR >> cur)
        {
            inp.push_back(cur);
        }
        Node *root = new Node(stoi(inp[0]));
        queue<Node *> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < inp.size())
        {
            Node *temp = q.front();
            q.pop();
            string val = inp[i];
            // left
            if (val != "N")
            {
                temp->left = new Node(stoi(val));
                q.push(temp->left);
            }
            i++;
            if (i >= inp.size())
                break;
            val = inp[i];
            // right
            if (val != "N")
            {
                temp->right = new Node(stoi(val));
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }

public:
    void takeInput()
    {
        getline(cin, s);
    }

    void execute()
    {

        Node *tree = buildTree(s);
        int ans = minVal(tree);
    }

    void executeAndPrintOutput()
    {

        Node *tree = buildTree(s);
        int ans = minVal(tree);
        cout << ans << endl;
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}




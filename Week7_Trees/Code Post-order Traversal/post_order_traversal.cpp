/*
POST-ORDER TRAVERSAL

Problem statement
Given a generic tree, print the post-order traversal of given tree.

The post-order traversal is: visit child nodes first and then root node.


Constraints:
Time Limit: 1 sec


Explanation
For 10 , total 3 children are there : 20 30 40
For  20, total 2 children are there : 400 50
So, the output will be 400 50 20 30 40 10

-----------------------------------------------------------------------
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
-----------------------------------------------------------------------
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        printPostOrder(root->children[i]);
    }

    cout << root->data << " ";
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printPostOrder(root);
}

/*
SUM OF ALL NODES

Problem statement
Given a generic tree, find and return the sum of all nodes present in the given tree.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec



--------------------------------------------------------------------------------------
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
190
--------------------------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <queue>
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

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    if (root == nullptr) {
        return 0;
    }
    
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++) {
        sum += sumOfNodes(root->children[i]);
    }
    
    return sum;
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
    cout << sumOfNodes(root);
}


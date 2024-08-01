/*
STRUCTURALLY IDENTICAL

Problem statement
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the
same way, then the trees are called identical.  


Constraints:
Time Limit: 1 sec


------------------------------------------------------------------------------------------------
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
------------------------------------------------------------------------------------------------


------------------------------------------------------------------------------------------------
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
------------------------------------------------------------------------------------------------
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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    // If one root is null and the other is not, trees are not identical
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    // Check if the current nodes' data are the same
    if (root1->data != root2->data) {
        return false;
    }

    // Check if the number of children is the same
    if (root1->children.size() != root2->children.size()) {
        return false;
    }

    // Recursively check for each pair of children
    for (size_t i = 0; i < root1->children.size(); ++i) {
        if (!areIdentical(root1->children[i], root2->children[i])) {
            return false;
        }
    }

    return true;
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
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}



/*
MAX DATA NODE
level : moderate

Problem statement
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.

Return null if tree is empty.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec



--------------------------------------------------------------------------------------------------------------------------
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
--------------------------------------------------------------------------------------------------------------------------
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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
     if (root == nullptr) {
        return nullptr;
    }

    TreeNode<int>* maxNode = root;

    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if (temp != nullptr && temp->data > maxNode->data) {
            maxNode = temp;
        }
    }

    return maxNode;
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
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }
}

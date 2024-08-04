/*
NODE WITH MAXIMUM CHILD SUM
level : moderate

Problem statement
Given a generic tree, find and return the node for which sum of its data and data of all its child
nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.


Constraints:
Time Limit: 1 sec
0 < Node's val <= 10^5



-----------------------------------------------------------------------------------------------------
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
-----------------------------------------------------------------------------------------------------
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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here

    if (root == nullptr) {
        return nullptr;
    }

    // Initialize the node with the maximum sum as the root node initially
    TreeNode<int>* maxNode = root;
    int maxSum = root->data;

    // Calculate the initial sum for the root node
    for (TreeNode<int>* child : root->children) {
        maxSum += child->data;
    }

    // Use a queue for level order traversal
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        TreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();

        // Calculate the sum for the current node
        int currentSum = currentNode->data;
        for (TreeNode<int>* child : currentNode->children) {
            currentSum += child->data;
            pendingNodes.push(child);
        }

        // Update the maximum sum and the corresponding node if needed
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxNode = currentNode;
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

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}



/*
SECOND LARGEST ELEMENT IN TREE

Problem statement
Given a generic tree, find and return the node with second largest value in given tree.

Note: Return NULL if no node with required value is present.


Constraints:
Time Limit: 1 sec


---------------------------------------------------------------------------------------
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
---------------------------------------------------------------------------------------
*/


#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

void getSecondLargestNodeHelper(TreeNode<int>* root, int& largest, int& secondLargest) {
    if (root == nullptr)
        return;

    // Update largest and secondLargest if the current node's data is larger than current largest
    if (root->data > largest) {
        secondLargest = largest;
        largest = root->data;
    }
    // Update secondLargest if the current node's data is larger than current secondLargest but smaller than largest
    else if (root->data > secondLargest && root->data != largest) {
        secondLargest = root->data;
    }

    // Recursively check for children
    for (TreeNode<int>* child : root->children) {
        getSecondLargestNodeHelper(child, largest, secondLargest);
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if (root == nullptr)
        return nullptr;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    // Traverse the tree to find the second largest element
    getSecondLargestNodeHelper(root, largest, secondLargest);

    // If there is no second largest (e.g., all nodes have the same value), return nullptr
    if (secondLargest == INT_MIN)
        return nullptr;

    // Otherwise, find and return the node with the second largest value
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        TreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();

        if (currentNode->data == secondLargest)
            return currentNode;

        for (TreeNode<int>* child : currentNode->children) {
            pendingNodes.push(child);
        }
    }

    return nullptr; // This line should never be reached
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}




/*
REPLACE WITH DEPTH
level : moderate

Problem statement
You are given a generic tree. You have to replace each node with its depth value.
You just have to update the data of each node, there is no need to return or print 
anything.


Constraints:
Time Limit: 1 sec



-----------------------------------------------------------------------------------
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
0 
1 1 1 
2 2
-----------------------------------------------------------------------------------
*/


#include <climits>
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

void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    if (root == nullptr)
        return;

    // Use a queue for level-order traversal
    queue<TreeNode<int>*> q;
    q.push(root);

    // Variable to store depth level
    int depth = 0;

    while (!q.empty()) {
        int nodesInCurrentLevel = q.size(); // Number of nodes in the current level

        // Process all nodes in the current level
        while (nodesInCurrentLevel--) {
            TreeNode<int>* current = q.front();
            q.pop();

            // Update the data of the current node with the depth value
            current->data = depth;

            // Enqueue children of the current node
            for (TreeNode<int>* child : current->children) {
                q.push(child);
            }
        }

        // Increment depth for the next level
        depth++;
    }
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

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);
}


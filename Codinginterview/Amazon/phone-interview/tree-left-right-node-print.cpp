#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printLeftmostNodes(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            // Print the first node of this level (leftmost node)
            if (i == 0 || i == levelSize - 1) {
                cout << currentNode->val << " ";
            }

            // Add children to the queue
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
    }
}

int main() {
    // Create a sample tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    //    /
    //   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);

    cout << "Leftmost nodes: ";
    printLeftmostNodes(root);
    cout << endl;

    return 0;
}
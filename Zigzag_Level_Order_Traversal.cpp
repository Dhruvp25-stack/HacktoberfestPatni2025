#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        leftToRight = !leftToRight;
        result.push_back(level);
    }

    return result;
}

// Driver Code (Sample Tree)
int main() {
    /*
        Constructed Binary Tree
              1
             / \
            2   3
           / \   \
          4   5   6

        Zigzag Output: [1], [3,2], [4,5,6]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    for (auto level : ans) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
}

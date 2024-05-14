#include <bits/stdc++.h>
using namespace std;

// 98. Validate Binary Search Tree

// ----- Approach -----

// start DFS with LEFT-MIN and RIGHT-MAX

// Base case : if (!root) return true;
// Base case : if (root->val <= left || root->val >= right) return false;

// for the LEFT subtree keep the left limit the same and set right limit to `curr_node->val`
// same for the right

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool dfs(TreeNode* root, long left, long right) {
        if (!root) return true;
        if (root->val <= left || root->val >= right)
            return false;
        
        if (dfs(root->left, left, root->val) &&
            dfs(root->right, root->val, right))
            return true;

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);      
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
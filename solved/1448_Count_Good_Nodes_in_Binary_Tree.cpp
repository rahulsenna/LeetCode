#include <bits/stdc++.h>
using namespace std;

// 1448. Count Good Nodes in Binary Tree


// ----- Approach ----
// dfs
// Count nodes if node->val >= maxval


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
    int dfs(TreeNode *root, int maxval){
        if (!root) return 0;
        int res = 0;

        maxval = max(maxval, root->val);
        if (root->val >= maxval) res = 1;

        res += dfs(root->left, maxval);
        res += dfs(root->right, maxval);
        return res;
        
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

int main()
{
    cout << "Hello, Sailor\n";
// bittukainsuranceA@1
	return(0);
}
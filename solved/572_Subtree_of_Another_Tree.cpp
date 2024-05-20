#include <bits/stdc++.h>
using namespace std;

// 572. Subtree of Another Tree


// ----- Approach -----
// * Break problem into simpler isSameTree Problem
// * recursively check isSameTree for entire root tree


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
    bool isSameTree(TreeNode* q, TreeNode* p) {
        if (!q && !p) return true;
        if (!q || !p) return false;
        return q->val == p->val && isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && subRoot) return false; 

        return  isSameTree(root, subRoot) || 
                isSubtree(root->left, subRoot) || 
                isSubtree(root->right, subRoot);
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
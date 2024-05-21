#include <bits/stdc++.h>
using namespace std;

// 235. Lowest Common Ancestor of a Binary Search Tree


// ----- Approach -----
// * if both node _p_ and _q_ is less than root then move left
// * if both node _p_ and _q_ is greater than root then move right
// * else return root


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode *curr = root;
        while(curr) {
            if (p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else if (p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else
                return curr;
        }
        return root;
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
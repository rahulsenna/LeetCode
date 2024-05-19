#include <bits/stdc++.h>
using namespace std;

// 110. Balanced Binary Tree

/*        
                    543. Diameter of Binary Tree

                --------------- Approach --------------

1. Depth-First Search (DFS):
    * DFS
    * For each node, calculate the height of its left and right subtrees.
    
2. Return the Height:
    * Return the height of the subtree =  1 + max(leftHeight, rightHeight).

3. If difference is greater than 1 set bool _ballance_ to FALSE
*/ 

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
    int dfs (TreeNode* root, bool &balance) {
        if (!root) return 0;

        int left = dfs(root->left, balance);    // height of left subtree
        int right = dfs(root->right, balance);  // height of right subtree
        if (abs(left-right)>1) balance = false; 
        return max(left,right)+1;               // height
    }
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        dfs(root, balance);
        return balance;
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
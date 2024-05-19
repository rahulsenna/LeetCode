#include <bits/stdc++.h>
using namespace std;

/*        
                    543. Diameter of Binary Tree

                --------------- Approach --------------

1. Depth-First Search (DFS):
    * DFS
    * For each node, calculate the height of its left and right subtrees.
    * diameter =  heights (left + right) subtrees.

2. Update the Maximum Diameter:
    * Keep track of the maximum diameter encountered during the DFS traversal.
    
3. Return the Height:
    * Return the height of the subtree =  1 + max(leftHeight, rightHeight).
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
    int res = 0;
    int dfs(TreeNode *root){
        if (!root) return -1;

        int left = dfs(root->left); // height of left subtree
        int right = dfs(root->right); // height of right subtree

        res = max(res, left+right+2); // Diameter
        return max(left,right)+1; // Height

    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
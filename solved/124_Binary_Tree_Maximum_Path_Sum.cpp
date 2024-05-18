#include <bits/stdc++.h>
using namespace std;


// 124. Binary Tree Maximum Path Sum


// ----- Approach -----
//    1. dfs
//    2. keep track of max_len
//    3. Only _one split_ allowed for a valid path
//    4. _return val_ should be _max_len_ wihtout a _split_ in that subtree

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
    int dfs (TreeNode* root, int &max_len) {
        if (!root)
            return 0;
        int head = root->val;
        int left = max(0,dfs(root->left, max_len)); 
        int right = max(0,dfs(root->right,max_len));
        
        max_len = max(max_len,head+left+right); // max_len of current subtree
        return head + max(left,right); // max_len without split
    }
    int maxPathSum(TreeNode* root) {
        int max_len = INT_MIN;
        
        dfs(root, max_len);
        return max_len;
        
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
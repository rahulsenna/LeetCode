#include <bits/stdc++.h>
using namespace std;

// 102. Binary Tree Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode *> q = {root};
        
        vector<vector<int>> res;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i=0; i<size;++i) {
                level.push_back(q.front()->val);
                if (q.front()->left) q.push_back(q.front()->left);
                if (q.front()->right) q.push_back(q.front()->right);
                q.pop_front();
            }
            res.push_back(level);
        }
        return res;
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
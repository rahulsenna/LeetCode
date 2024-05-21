#include <bits/stdc++.h>
using namespace std;

// 199. Binary Tree Right Side View

// ----- Approach -----
// * BFS
// * Add last node of current level to the Result <vector>

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode *> q = {root};
        vector<int> res;

        while(!q.empty()) {
            int size = q.size();
            for (int i=0;i<size;++i) {
                auto node = q.front();
                q.pop_front();
                if (i+1==size)                  // Last node of this level
                    res.push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }

        }
        return res;
    }
};

int main()
{
    // [1,2,3,null,5,null,4] tree

    TreeNode *tree = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4)));

    Solution sol;
    auto res = sol.rightSideView(tree);

    cout << "Hello, Sailor\n";

	return(0);
}
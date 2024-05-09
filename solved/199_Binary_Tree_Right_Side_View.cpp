#include <bits/stdc++.h>
using namespace std;


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
                if (i==size-1)
                    res.push_back(q.front()->val);

                if (q.front()->left) q.push_back(q.front()->left);
                if (q.front()->right) q.push_back(q.front()->right);
                q.pop_front();
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
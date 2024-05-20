#include <bits/stdc++.h>
using namespace std;

// 100. Same Tree

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

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        return  p->val == q->val &&  
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right); 
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
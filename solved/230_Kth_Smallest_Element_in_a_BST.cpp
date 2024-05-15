#include <bits/stdc++.h>
using namespace std;


// 230. Kth Smallest Element in a BST

// ----- Approach -----

// When the left subtree returns, it signifies that we have reached the smallest element. 
// Simply keep a count to check whether we have reached the Kth smallest element.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Recursive Method
class Solution {
public:
    void inorderTraversal(TreeNode* root, int k, int& count, int& result)
    {
        if (!root)
            return;
        inorderTraversal(root->left, k, count, result);
        count++;
        if (count == k) 
            result = root->val;
        if (count >= k) 
            return;

        
        inorderTraversal(root->right, k, count, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        int res = 0;
        inorderTraversal(root, k, count, res);
        return res;
    }
};
// ---------------------------------------------------

// Iterative Method

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *curr = root;

        while(curr || !s.empty()) {

            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            if (res.size()==k)
                return res.back();
            
            curr = curr->right;
        }
        assert(false);
        return -1;
    }
};

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
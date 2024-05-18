#include <bits/stdc++.h>
using namespace std;

// 105. Construct Binary Tree from Preorder and Inorder Traversal

// Key Observations
// Preorder Property: The _first element_ in the _preorder_ traversal is always the _root_ of the tree or subtree.
// Inorder Property: The _position_ of the _root_ element (found in the _preorder_) in the inorder traversal _splits_ the tree into the _left_ and _right_ subtrees.




// ----- Approach -----

// Identify the _root_ from the preorder traversal.
// Find the _root_ in the inorder traversal. The elements to the left of the root in the inorder list form the left subtree, and the elements to the right form the right subtree.
// Recursively apply the same process to construct the left and right subtrees.



// Efficient Solution Explanation
// We use a hashmap to store the indices of the inorder elements for quick lookup. This avoids repeated scanning of the inorder array.



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Inorder Traversal: Visits nodes in the order: left subtree, root, right subtree.
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}
// Preorder Traversal: Visits nodes in the order: root, left subtree, right subtree.
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << " ";
}


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return 0;

        TreeNode *root = new TreeNode(preorder.front());

        int mid = find(inorder.begin(),inorder.end(), preorder.front()) -inorder.begin();

        vector<int> preorder_l(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> preorder_r(preorder.begin()+1+mid, preorder.end());
        vector<int> inorder_l(inorder.begin(), inorder.begin()+mid);
        vector<int> inorder_r(inorder.begin()+mid+1, inorder.end());

        root->left = buildTree(preorder_l, inorder_l);
        root->right = buildTree(preorder_r, inorder_r);

        return root;
    }
};

// Optimized
class Solution {
public:
    unordered_map<int,int> map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i =0;i<inorder.size();++i)
            map[inorder[i]] = i;

        return build(preorder, 0, preorder.size()-1,
                     inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int beg_preorder_idx, int end_preorder_idx,  
                        vector<int>& inorder, int beg_inorder_idx, int end_inorder_idx) {
        
        if (beg_preorder_idx > end_preorder_idx || beg_inorder_idx > end_inorder_idx)
            return 0;
        TreeNode *root = new TreeNode(preorder[beg_preorder_idx]);
        int mid = map[root->val];
        int left_size = mid - beg_inorder_idx;

        root->left = build(preorder, beg_preorder_idx+1, beg_preorder_idx+left_size,
                            inorder, beg_inorder_idx, mid-1);
        root->right = build(preorder, beg_preorder_idx+left_size+1, end_preorder_idx,
                            inorder, mid+1, end_inorder_idx);
        
        return root;
    }

};


int main()
{
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    std::cout << "In-order traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    cout << "Hello, Sailor\n";

	return(0);
}
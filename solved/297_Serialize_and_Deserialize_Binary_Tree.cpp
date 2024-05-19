#include <bits/stdc++.h>
using namespace std;

// 297. Serialize and Deserialize Binary Tree

/*
                    Approach
The approach uses Depth-First Search (DFS) for both serialization and deserialization.

Serialization
    DFS Traversal:
        Perform a preorder traversal (root, left, right).
        For each node:
            Append its value to the string followed by a space.
            For a null node, append a special marker ("N") followed by a space.
    
    
Deserialization
    Splitting the String:
        Split the serialized string by spaces to get a list of values and markers.
    
    Rebuilding the Tree:
        Use a recursive function to rebuild the tree:
        Read the current value (use an index to keep track).
        If the value is "N", return null.
        Otherwise, create a new TreeNode with the current value.
        Recursively build the left and right subtrees.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void dfs_serialize(TreeNode* root, string &s) {
        if (!root) {
            s += "N ";
            return;
        }

        s += to_string(root->val) + " ";
        dfs_serialize(root->left, s);
        dfs_serialize(root->right, s);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs_serialize(root, s);
        return s;
    }
    int idx = 0;
    TreeNode* dfs_deserial(vector<string> &s) {
        if (s[idx] == "N") {
            idx++;
            return 0;
        }
        TreeNode *root = new TreeNode(stoi(s[idx++]));
        root->left = dfs_deserial(s);
        root->right = dfs_deserial(s);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
		vector<string> tokens(istream_iterator<string>(ss), {});
        return dfs_deserial(tokens);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
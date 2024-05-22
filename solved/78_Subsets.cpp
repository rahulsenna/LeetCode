#include <bits/stdc++.h>
using namespace std;

// 78. Subsets

/*     
                                Approach

1. DFS Traversal:

    Use a DFS helper function to explore all possible combinations.
    At each step, decide whether to include the current element in the subset or not.
2. Backtracking:

    After including an element, recursively explore further elements.
    After exploring, backtrack by removing the last included element and explore the possibility of not including it.
3. Base Case:

    If the current index exceeds the size of the array, add the current subset to the result and return. */

class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(int idx, vector<int>& nums) {
        if (idx > nums.size()-1) {
            res.push_back(subset);
            return;
        }

        // inlude nums[idx] 
        subset.push_back(nums[idx]);
        dfs(idx+1, nums);

        // Backtrack and do not include nums[idx] in the subset
        subset.pop_back();
        dfs(idx+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,3};

    Solution sol;
    sol.subsets(nums);
    cout << "Hello, Sailor\n";

	return(0);
}
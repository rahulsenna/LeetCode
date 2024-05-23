#include <bits/stdc++.h>
using namespace std;

// 39. Combination Sum

// ----- Approach -----

// * DFS decison tree + Backtrack

// Recursive Exploration:

//  * The current candidate number (candidates[idx]) is added to nums.
//  * The dfs function is called recursively with the same index idx (allowing the same number to be reused) and an updated total (total + candidates[idx]).
//  * After the recursive call, backtracking is performed by removing the last number added to nums.
//  * The dfs function is then called recursively with the next index (idx + 1), excluding the current candidate number from the combination.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();

        // Define the DFS function as a lambda
        function<void(int, vector<int>&, int)> dfs = 
        [&](int idx, vector<int>& nums, int total)
        {
            if (total == target)
            {
                res.push_back(nums);
                return;
            }
            if (idx >= n || total > target)
                return;
            
            nums.push_back(candidates[idx]);
            dfs(idx, nums, total + candidates[idx]);

            nums.pop_back();
            dfs(idx + 1, nums, total);
        };

        vector<int> nums;
        dfs(0, nums, 0);
        return res;
    }
};


int main()
{
    cout << "Hello, Sailor\n";

	return(0);
}
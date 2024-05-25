#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> res;

    function<void(int)> backtrack = [&](int start) {
        if (start == nums.size()-1)
        {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i)
        {
        	 swap(nums[i], nums[start]);
             backtrack(start+1);
        	 swap(nums[i], nums[start]);
        }
    };

    backtrack(0);
    return res;
        
    }
};
// @lc code=end


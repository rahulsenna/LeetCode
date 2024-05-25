#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& numbers) {
        
        std::ranges::sort(numbers);
        vector<vector<int>> res;
        
        function<void(int, vector<int>&)> backtrack = [&](int start, vector<int> nums)
        {
            if (start == nums.size()-1)
            {
                res.push_back(nums);
                return;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                if (i!=start && nums[i]==nums[start])
                    continue;
            	swap(nums[i], nums[start]);
                backtrack(start+1, nums);
            }
        };
        backtrack(0,numbers);
        return res;
    }
};
// @lc code=end


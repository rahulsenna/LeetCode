/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (57.36%)
 * Likes:    9619
 * Dislikes: 303
 * Total Accepted:    921.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> res;
        vector<int> subset;
        function<void(int)> backtrack = [&](int idx)
        {
            if (idx == nums.size())
            {
                res.push_back(subset);
                return;
            }
                
            subset.push_back(nums[idx]); // include nums[idx]
            backtrack(idx+1);
            subset.pop_back();

            while (idx+1<nums.size() && nums[idx]==nums[idx+1]) // skip the duplicates
                idx++;
            backtrack(idx+1);           // don't include nums[idx]
        };

        backtrack(0);
        return(res);
    }
};
// @lc code=end


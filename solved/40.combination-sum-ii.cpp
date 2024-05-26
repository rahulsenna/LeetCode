/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (54.60%)
 * Likes:    10327
 * Dislikes: 290
 * Total Accepted:    976.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note: The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output: 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output: 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        ranges::sort(candidates);

        function<void(int, int)> backtrack = [&](int idx, int total)
        {
            if (total == target)
            {
                res.push_back(arr);
                return;
            }
            if (total > target || idx >= candidates.size())
                return;
            
            arr.push_back(candidates[idx]);
            backtrack(idx+1, total+candidates[idx]);
            
            while (idx+1<candidates.size() && candidates[idx]==candidates[idx+1])
                idx++;

            arr.pop_back();
            backtrack(idx+1, total);
        };

        backtrack(0,0);
        return res;
    }
};
// @lc code=end
// [1,1,2,5,6,7,10]


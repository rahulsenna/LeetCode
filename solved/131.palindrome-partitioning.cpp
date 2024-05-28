/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (69.20%)
 * Likes:    12731
 * Dislikes: 485
 * Total Accepted:    889.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
            
    vector<vector<string>> res;
    vector<char> cand;
    vector<string> part;

    function<bool(int, int)> palindrome = [&](int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    };

    function<void(int)> dfs = [&](int start)
    {
        if (start >= s.length())
        {
            res.push_back(part);
            return;
        }
           
        for (int i = start; i < s.length(); ++i) {
            if (palindrome(start, i))
            {
                part.push_back(s.substr(start, i-start+1));
                dfs(i + 1);
                part.pop_back();
            }
        }
        };

        dfs(0);
        return(res);
    }
};
// @lc code=end


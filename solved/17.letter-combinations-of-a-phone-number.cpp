/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (60.55%)
 * Likes:    18368
 * Dislikes: 987
 * Total Accepted:    2M
 * Total Submissions: 3.4M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<string> keys = {"","", "abc", "def", 
                            "ghi", "jkl", "mno", 
                            "pqrs", "tuv", "wxyz"};


    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<int> numbers = {digits.begin(), digits.end()};
        for (auto &n : numbers)
            n -= '0';
        vector<string> res;
        vector<char> comb;
        function<void(int)> rec = [&](int s_dig)
        {
            if (comb.size()==digits.length())
            {
                res.push_back({comb.begin(), comb.end()});
                return;
            }            
            auto &chars = keys[numbers[s_dig]];
            for (int j = 0; j < chars.length(); ++j)
            {
                comb.push_back(chars[j]);
                rec(s_dig+1);
                comb.pop_back();
            }
        };
        rec(0);
        return res;
    };
};
// @lc code=end


/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (74.05%)
 * Likes:    3819
 * Dislikes: 261
 * Total Accepted:    392.1K
 * Total Submissions: 528.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
         
        if (n==2 || n==3) return {};
        vector<vector<bool>> board(n, vector<bool>(n, false));
        unordered_map<int,bool> NegDiag = {};
        unordered_map<int,bool> PosDiag = {};
        
        function<bool(int, int)>  is_valid = [&] (int row, int col)
        {
            for (int i = 0; i < n; ++i)
            {
                if (board[i][col])
                    return false;
            }

            for (bool r: board[row])
            {
                if (r)
                    return false;
            }
        if (PosDiag[row+col])  // row+col is same constant for all Pos Diagonals
            return false;
        if (NegDiag[row-col])
            return false;

        return true;
    };
    

    vector<vector<string>> res;
    function<void(int)> rec = [&](int row)
    {
        
        if (row >= n)
        {
            vector<string> t;
            for (auto &e: board)
            {
            	string s(n, '.');
                for (int i = 0; i < n; ++i)
                {
                	if (e[i])
                    {
                        s[i]= 'Q';
                        t.push_back(s);
                        break;
                    }
                }
            }
            res.push_back(t);

            return;
        }
        for (int col = 0; col < n; ++col)
        {
            if (is_valid(row,col))            
            {
                board[row][col] = true;
                PosDiag[row+col] = true;
                NegDiag[row-col] = true;
                rec(row+1);
                board[row][col] = false;
                PosDiag[row+col] = false;
                NegDiag[row-col] = false;
            }
        }
        
    };

    rec(0);
    
    return res.size();
    }
};
// @lc code=end


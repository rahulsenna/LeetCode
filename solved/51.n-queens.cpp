/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.37%)
 * Likes:    12225
 * Dislikes: 284
 * Total Accepted:    732.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [["Q"]]
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
    vector<vector<string>> solveNQueens(int n)
    {
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

#if 0 
        // Check Diagonals in a simple way
        int i = row, j= col;
        while(++i <n && ++j <n)
            if (board[i][j])
                return false;
        i = row, j= col;
        while(--i >=0 && --j >=0)
            if (board[i][j])
                return false;

        i = row, j= col;
        while(--i >=0 && ++j <n)
            if (board[i][j])
                return false;

        i = row, j= col;
        while(++i <n && --j >=n)
            if (board[i][j])
                return false;
#else
    // Check Diagonals with NegDiag ans PosDiag Optimization
    if (PosDiag[row+col])  // row+col is same constant for all Pos Diagonals
        return false;
    if (NegDiag[row-col])
        return false;

#endif

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
    
    return res;

}
};
// @lc code=end


/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (42.86%)
 * Likes:    15707
 * Dislikes: 661
 * Total Accepted:    1.7M
 * Total Submissions: 3.9M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    int ROWS = board.size();
    int COLS = board[0].size();
    int idx = 0;

    // ----------------- Optimizations ----------------------------

    // Quick check: If the length of the word exceeds the total number of cells on the board, it can't exist
    if (word.size() > ROWS * COLS)
        return false;

    vector<char> char_arr(word.begin(), word.end());
    vector<int> counts(256, 0); // Array to store counts of each character
    
    // Count the occurrence of each character on the board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
            counts[board[r][c]]++;
    }
    
    // Adjust the order of characters in the wordChar array based on their frequency counts to optimize search
    int len = char_arr.size();
    for (int i = 0; i < len / 2; i++)
    {
        if (counts[char_arr[i]] > counts[char_arr[len - 1 - i]])
        {
            for (int j = 0; j < len / 2; j++)
                swap(char_arr[j], char_arr[len - 1 - j]);
            
            break;
        }
    }
    
    // Decrease counts of characters in the word from the board
    for (char c : char_arr)
    {
        if (--counts[c] < 0)
            return false; // If there are more occurrences of a character in the word than on the board, return false
    }
    // ----------------- Optimizations END ----------------------------

    unordered_map<int, bool> visited;
    bool res = false;

    function<void(int, int)> backtrack = [&](int row, int col)
    {
        if (idx == word.length())
            res = true;
        
        if (res)
            return;

        if (row < 0 || col < 0 || col >= COLS || row >= ROWS)
            return;

        if (visited[1000 * row + col])
            return;

        if (board[row][col] == char_arr[idx])
        {
            idx++;
            visited[1000 * row + col] = true;
        }
        else
            return;

        backtrack(row, col + 1);
        backtrack(row + 1, col);
        backtrack(row, col - 1);
        backtrack(row - 1, col);
        
        idx--;
        visited[1000 * row + col] = false;
    };

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            idx = 0;
            backtrack(r, c);
            if (res)
                return true;
        }
    }

    return res;
}
};
// @lc code=end


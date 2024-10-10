#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif

int main()
{
    setup();

    s64 t, row_n, col_n;
    cin >> t;
    const int directions[4][2] = {{-1, 1}, {-1, -1}, {1, 1}, {1, -1}}; // Up-right, Up-left, Down-right, Down-left

    while(t--)
    {
        cin >> row_n >> col_n;

        vector<vector<int>> board(row_n, vector<int>(col_n));
        for (auto &row: board)
        {
        	for (auto &e: row)
        		cin >> e;
        }
        int res = 0;
        for (int start_row = 0; start_row < row_n; ++start_row)
        {
            for (int start_col = 0; start_col < col_n; ++start_col)
            {
                int sum = board[start_row][start_col];
                for (const auto& dir : directions)
                {
                    int row = start_row + dir[0];
                    int col = start_col + dir[1];
                    while (row >= 0 && row < row_n && col >= 0 && col < col_n) 
                    {
                        sum += board[row][col];
                        row += dir[0];
                        col += dir[1];
                    }
                }
                res = max(sum, res);
            }
        }
        std::cout << res << '\n';
        
        int d = 5;
    }
 
    return 0;
}

// https://codeforces.com/contest/1676/problem/D
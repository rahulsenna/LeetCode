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
    freopen("Day04.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif

std::vector<std::string> 
get_right_to_left_diagonals(const std::vector<std::string>& grid)
{
    if (grid.empty()) return {};
    
    int m = grid.size();
    int n = grid[0].length();
    std::vector<std::string> diagonals;
    
    for (int diagonal = 0; diagonal < m + n - 1; ++diagonal)
    {
        std::string current_diagonal;
        
        int row = diagonal < n ? 0 : diagonal - n + 1;
        int col = diagonal < n ? diagonal : n - 1;
        
        while (row < m && col >= 0)
        {
            if (col < grid[row].length())
                current_diagonal += grid[row][col];
            
            ++row;
            --col;
        }
        
        if (!current_diagonal.empty()) 
            diagonals.push_back(current_diagonal);
        
    }
    
    return diagonals;
}


std::vector<std::string>
get_left_to_right_diagonals(const std::vector<std::string>& grid) 
{
    if (grid.empty()) return {};
    
    int m = grid.size();
    int n = grid[0].length();
    std::vector<std::string> diagonals;
    
    for (int diagonal = 0; diagonal < m + n - 1; ++diagonal)
    {
        std::string current_diagonal;
        
        int row = diagonal < n ? 0 : diagonal - n + 1;
        int col = diagonal < n ? n - diagonal - 1 : 0;
        
        while (row < m && row >= 0 && col < n)
        {
            if (col >= 0 && col < grid[row].length()) 
                current_diagonal += grid[row][col];
            ++row;
            ++col;
        }
        
        if (!current_diagonal.empty())
            diagonals.push_back(current_diagonal);
    }
    
    return diagonals;
}

std::vector<std::string>
get_verticals(const std::vector<std::string>& grid) 
{
    if (grid.empty()) return {};
    
    int m = grid.size();
    int n = grid[0].length();
    std::vector<std::string> verticals;

    for (int col = 0; col < n; ++col)
    {
        std::string current_vertical;
        for (int row = 0; row < m; ++row)
            current_vertical += grid[row][col];
        
        verticals.push_back(current_vertical);     
    }
    return verticals;
}

void part_one()
{
    string line;
    vector<string> horizontals;
    while(getline(cin, line))
        horizontals.push_back(line);

    vector<vector<string>> grid = {horizontals};
    grid.push_back(get_verticals(horizontals));
    grid.push_back(get_left_to_right_diagonals(horizontals));
    grid.push_back(get_right_to_left_diagonals(horizontals));
    
    int res = 0;

    for (auto &lines: grid)
    {
        for (auto &line: lines)
        {
            for (int i = 0; i < 2; ++i)
            {                
                int idx = 0;
                while(idx != -1)
                {
                    idx = line.find("XMAS", idx);
                    if (idx != -1)
                        res++;
                    else
                        break;
                    idx++;
                }
                reverse(line.begin(), line.end());
            }
        }
    }

    std::cout << "res: " << res << '\n';
}

void part_two()
{
    string line;
    vector<string> grid;
    while(getline(cin, line))
        grid.push_back(line);

    int m = grid.size();
    int n = grid[0].length();
    int res = 0;
    for (int row = 1; row < m-1; ++row)
    {
        for (int col = 1; col < n-1; ++col)
        {
            if (grid[row][col] == 'A')
            {
                char corners[4] = 
                {
                    grid[row-1][col-1], // top_left
                    grid[row+1][col+1], // bottom_right
                    grid[row-1][col+1], // top_right
                    grid[row+1][col-1]  // bottom_left
                };
                bool invalid_corners = false;
                for (int i = 0; i < 4; ++i)
                {
                    
                	if (corners[i] != 'M' and corners[i] != 'S') // if anything but M or S
                	{ 
                		invalid_corners = true;
                        break;
                	}
                }

                if (invalid_corners or corners[0]==corners[1] or corners[2]==corners[3])
                    continue;

                res++;
            }
        }
    }
    std::cout << "res: " << res << '\n';

    
}
int main()
{
    setup();
    // part_one();
    part_two();

    return 0;
}

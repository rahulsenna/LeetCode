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
    freopen("Day06.txt", "r", stdin),/*  freopen("output.txt", "w", stdout), */ freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif

set<pair<int,int>> gaurd_been(vector<string> &grid, int curr_x, int curr_y)
{
    int rows = grid.size(), cols = grid[0].size();
    auto outside = [&](int x, int y) {return (x < 0 or y < 0 or y >= rows or x >= cols);};

    pair<int, int> DIRS[4] = { { 0,-1},{ 1, 0},{ 0, 1},{-1, 0} };
    int dir_idx = 0;
    set<pair<int,int>> gaurd_seen;    
    gaurd_seen.insert({curr_x,curr_y});

    while (1)
    {
        auto [dir_x, dir_y] = DIRS[dir_idx];

        while (1)
        {
            if (outside(curr_x + dir_x, curr_y + dir_y))
                return gaurd_seen;
            if (grid[curr_y + dir_y][curr_x + dir_x] == '#')
                break;
            
            curr_x += dir_x;
            curr_y += dir_y;
            gaurd_seen.insert({ curr_x, curr_y });
        }
        dir_idx = (dir_idx + 1) % 4;
    }
    return {};
}

void part_one()
{
    vector<string> grid;
    string line;
    int y = 0, curr_x, curr_y;

    while(getline(cin, line))
    {
        auto x = line.find('^');
        if (x!= -1)
        {
            curr_x = x, curr_y = y;
        }
        grid.push_back(line);
        y++;
    }
    int res = gaurd_been(grid, curr_x, curr_y).size();
    std::cout << "res: " << res << '\n';
}



void part_two()
{
    vector<string> grid;
    string line;
    int y = 0, curr_x, curr_y, start_x, start_y;

    while(getline(cin, line))
    {
        auto x = line.find('^');
        if (x!= -1)
        {
            start_x = x, start_y = y;
        }
        grid.push_back(line);
        y++;
    }
    int rows = grid.size(), cols = grid[0].size();

    auto outside = [&](int x, int y) {return (x < 0 or y < 0 or y >= rows or x >= cols);};
    pair<int, int> DIRS[4] = { { 0,-1},{ 1, 0},{ 0, 1},{-1, 0} };

    auto in_loop = [&]()
    {
        int dir_idx = 0;
        curr_x =start_x;
        curr_y =start_y;

        std::vector<bool> seen(rows*cols*4);
        int turns = 0;
        while (1)
        {
            auto [dir_x, dir_y] = DIRS[dir_idx];
            while (1)
            {
                if (outside(curr_x + dir_x, curr_y + dir_y))
                    return false;
                if (grid[curr_y + dir_y][curr_x + dir_x] == '#')
                    break;
                
                curr_x += dir_x;
                curr_y += dir_y;
                
                int hash = (curr_x*cols+curr_y)*4+dir_idx;
                if (seen[hash])
                    return true;
                seen[hash] = true;
            }
            dir_idx = (dir_idx + 1) % 4;
        }
    };
    int res = 0;

    set<pair<int,int>> gaurds_positions = gaurd_been(grid, start_x, start_y);
    gaurds_positions.erase(make_pair(start_x, start_y));
    for (auto [x,y]: gaurds_positions)
    {
    	grid[y][x] = '#';
        if (in_loop())
            res++;
                
        grid[y][x] = '.';
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

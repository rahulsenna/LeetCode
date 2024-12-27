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
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
}


void part_one()
{
    vector<string> grid;
    string line;
    while(getline(cin,line))
        grid.push_back(line);

    int width = line.size(), height = grid.size();

    std::vector<bool> seen(width*height, 0);
    pair<int,int> DIRs[4] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    
    auto outside = [&](int x, int y) { return (x < 0 or x >= width or y < 0 or y >= height);};
    
    auto bfs = [&](int row, int col)
    {
        int peri = 0;
        int area = 1;
        char c = grid[row][col];

        vector<pair<int, int>> q = { {row,col} };

        do
        {
            auto [y, x] = q.back();
            q.pop_back();

            for (auto [dx, dy] : DIRs)
            {
                int xx = dx + x, yy = dy + y;
                if (outside(xx, yy) or grid[yy][xx] != c)
                    peri++;
                else if (not seen[(yy) * height + (xx)])
                {
                    q.push_back({ yy, xx });
                    seen[(yy) * height + (xx)] = true;
                    area++;
                } 
            }
        } while (not q.empty());

        return peri * area;
    };
    
    int res = 0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (not seen[height * y + x])
            {
                seen[height * y + x] = 1;
                res += bfs(y,x);
            }
        }
    }
    
    std::cout << "part_one: " << res << '\n'; 
}

void part_two()
{
    vector<string> grid;
    string line;
    while(getline(cin,line))
        grid.push_back(line);

    int width = line.size(), height = grid.size();

    std::vector<bool> seen(width*height, 0);
    pair<int,int> DIRs[4] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    
    auto outside = [&](int x, int y) { return (x < 0 or x >= width or y < 0 or y >= height);};
    
    auto bfs = [&](int row, int col)
    {
        int peri = 0;
        int area = 1;
        char c = grid[row][col];

        vector<pair<int, int>> q = { {row,col} };

        int corners = 0;
        do
        {
            auto [y, x] = q.back();
            q.pop_back();

            int diff[4] = {/* right */ 0, /* left */ 0, /* up */ 0, /* down */ 0 };
            int diff_idx = 0;

            for (auto [dx, dy] : DIRs)
            {
                int xx = dx + x, yy = dy + y;
                if (outside(xx, yy) or grid[yy][xx] != c)
                {
                    diff[diff_idx] = 1;
                }
                else if (not seen[(yy) * height + (xx)])
                {
                    q.push_back({ yy, xx });
                    seen[(yy) * height + (xx)] = true;
                    area++;
                }
                diff_idx++;
            }

            // outer corner (L shaped diff)
            if (diff[0] and diff[2])
                corners++;
            if (diff[0] and diff[3])
                corners++;
            if (diff[1] and diff[2])
                corners++;
            if (diff[1] and diff[3])
                corners++;
            
            // inner corner (L shaped same, diag diff)
            if (not diff[0] and not diff[2] and grid[y - 1][x + 1] != c)
                corners++;
            if (not diff[0] and not diff[3] and grid[y + 1][x + 1] != c)
                corners++;
            if (not diff[1] and not diff[2] and grid[y - 1][x - 1] != c)
                corners++;
            if (not diff[1] and not diff[3] and grid[y + 1][x - 1] != c)
                corners++;

        } while (not q.empty());

        return corners * area;
    };
    
    int res = 0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (not seen[height * y + x])
            {
                seen[height * y + x] = 1;
                res += bfs(y,x);
            }
        }
    }
    
    std::cout << "part_two: " << res << '\n';     
}

int main()
{
    setup();
    // part_one();
    part_two();
    return 0;
}

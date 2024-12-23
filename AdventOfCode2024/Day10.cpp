#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
    freopen("Day10.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
}



int solve(bool count_all_path)
{
    vector<vector<int>> grid;
    string line;
    vector<pair<int, int>> trailheads;
    int y = 0;
    while (getline(cin, line))
    {
        vector<int> row(line.size());
        int x = 0;
        for (auto c : line)
        {
            row[x] = c - '0';
            if (c == '0')
                trailheads.emplace_back(x, y);
            x++;
        }
        grid.emplace_back(row);
        y++;
    }
    int height = y, width = line.size();
    auto outside = [&](int w, int h) { return h >= height or h < 0 or w >= width or w < 0;};

    pair<int, int> DIRs[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    set<pair<int, int>> seen;
    function<void(int, int, int, int&)> walk_trail = [&](int col, int row, int last_step, int& score)
    {
        if (outside(col, row))
            return;
        if (grid[row][col] == 9)
        {
            if (not count_all_path)
            {
                if (seen.count(make_pair(col, row)))
                    return;
                seen.insert(make_pair(col, row));
            }
            
            score++;
            return;
        }


        for (int d = 0; d < 4; ++d)
        {
            auto [c, r] = DIRs[d];
            int cc = col + c, rr = row + r;
            if (not outside(cc, rr) and grid[rr][cc] == (last_step + 1))
                walk_trail(cc, rr, last_step + 1, score);
        }

    };
    int res = 0;
    for (auto [col, row] : trailheads)
    {
        int score = 0;
        seen = {};
        walk_trail(col, row, 0, score);
        res += score;
    }

    return(res);
}

void part_one()
{
    std::cout << "part_one: " << solve(false) << '\n';
}

void part_two()
{
    std::cout << "part_two: " << solve(true) << '\n';
}

int main()
{
    setup();
    // part_one();
    part_two();
  
    return 0;
}

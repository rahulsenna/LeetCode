#include <bits/stdc++.h>
using namespace std;

struct State
{
    int x, y, cost;
    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }
};
const int W = 71, H = 71;
bool dijkstra(vector<string> grid)
{
    int dx[4] = {1, -1,  0, 0};
    int dy[4] = {0,  0, -1, 1};

    std::priority_queue<State, vector<State>, std::greater<>> q;
    q.push({0,0,0});
    std::vector<int> dist(W*H, INT_MAX);
    dist[0] = 0;

    while(not q.empty())
    {
        auto [curr_x, curr_y, cost] = q.top();
        q.pop();

        if (curr_x == W-1 and curr_y == H-1)
        {
            cout << "cost: " << cost << '\n';
            return true;
        }
        
        grid[curr_y][curr_x] = 'x';

        if (cost > dist[curr_y*H+curr_x])
            continue;
            
        for (int i = 0; i < 4; ++i)
        {
        	int next_x = curr_x+dx[i];
        	int next_y = curr_y+dy[i];

            if (next_x < 0 or next_x >= W or next_y < 0 or next_y >= H)
                continue;

            if (grid[next_y][next_x] != '.')
                continue;
            if (cost+1 < dist[next_y*H+next_x])
            {
                q.push({next_x, next_y,cost+1});
                dist[next_y*H+next_x] = cost+1;
            }
        }
    }
    return false;
}
void part_one()
{
    std::vector<string> grid (H, string(W,'.'));
    
    int x, y;
    char _;
    for (int i = 0; i <= 1024; ++i, (cin >> x >> _ >> y))
    {
        grid[y][x] = '#';   
    }    
    dijkstra(grid);
}

void part_two()
{
    std::vector<string> grid (H, string(W,'.'));
    
    int x, y;
    char _;
    int i;
    for (i = 0; i <= 1024; ++i, (cin >> x >> _ >> y))
    {
        grid[y][x] = '#';   
    }

    for (; i < 3450; ++i, (cin >> x >> _ >> y))
    {
        grid[y][x] = '#';
        if (!dijkstra(grid)) 
        {
            std::cout << "part_two: " << x << ',' << y << '\n';
            break;
        }
    }    
    
}

int main()
{
    freopen("Day18.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // part_one();
    part_two();
    return(0);
}
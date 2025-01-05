#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;      
    int dir; 
    int cost;
    // int prev_x, prev_y;
    vector<int> prev_list;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main()
{
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

    string line;
    std::vector<string> grid;
    pair<int,int> start,end;
    int Y =0;
    while(getline(cin, line))
    {
        int E = line.find("E");
        if (E != -1)
            end = {E, Y};
        int S = line.find("S");
        if (S != -1)
            start = {S, Y};
        
        grid.push_back(line);
        Y++;
    }
    
    // dijkstra

    int start_x = start.first, start_y = start.second;
    int rows = grid.size();
    int cols = grid[0].size();
    int min_cost = INT_MAX;
    std::vector<int> dist(rows * cols * 4, INT_MAX);
    dist[(start_x*cols+start_y)*4+1] = 0;
    std::set<int> seats;
    
    std::priority_queue<State, std::vector<State>, std::greater<>> pq;
    pq.push({start_x, start_y, 0, 0, {rows*start_y+start_x}}); // starting state, facing right (0)
    int times =0;
    
    const int dx[] = {1, -1,  0, 0};  
    const int dy[] = {0,  0, -1, 1};  
    
    while (!pq.empty())
    {
        State curr = pq.top();
        pq.pop();
        
    
        if (grid[curr.y][curr.x] == 'E')
        {
            if (curr.cost <= min_cost)
            {
                for (auto e : curr.prev_list)
                {
                    seats.insert(e);
                }
                seats.insert(curr.y*rows+curr.x);
                min_cost = min(curr.cost, min_cost);
            }
        }
        
        if (curr.cost > dist[(curr.x*cols+curr.y)*4+curr.dir])
            continue;
        
        for (int d = 0; d < 4; d++) {
            int new_x = curr.x + dx[d];
            int new_y = curr.y + dy[d];

            if (dx[curr.dir] + dx[d] == 0 and dy[curr.dir]+dy[d] == 0)
                continue; // opposite direction 
            
            if (grid[new_y][new_x] != '#')
            {
                int cost =  curr.cost+1;
                if (curr.dir != d)
                    cost += 1000;
                
                if (cost <= dist[(new_x*cols+new_y)*4+d])
                {
                    dist[(new_x*cols+new_y)*4+d] = cost;
                    curr.prev_list.emplace_back(rows * curr.y + curr.x);
                    pq.push({ new_x, new_y, d, cost, curr.prev_list });
                }
            }
        }
    }
    std::cout << "seats: " << seats.size() << '\n';
    std::cout << "min_cost: " << min_cost << '\n';

	return(0);
}
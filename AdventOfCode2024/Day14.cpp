#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
    fastio;
    freopen("Day14.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
}


void part_one()
{
    int W = 101, H = 103;
    string line;
    char _;
    int x,y, vx,vy;
    int res = 0;
    s64 quad[2][2] = { {0,0},{0,0} };
    while(getline(cin, line))
    {
        stringstream ss(line);
        ss >> _ >> _ >> x >> _ >> y >> _ >> _ >> vx >> _ >> vy;

        int px = ((x + (vx*100) % W)+W)%W;
        int py = ((y + (vy*100) % H)+H)%H;

        if (px == W/2 or py == H/2)
            continue;
        quad[px<W/2][py<H/2]++;
    }

    std::cout << "res: " << quad[0][0] * quad[0][1] * quad[1][0] * quad[1][1] << '\n';
}

void part_two()
{

    int W = 101, H = 103;
    string line;
    char _;
    int x,y, vx,vy;
    int res = 0;
    std::vector<pair<int,int>> pos,vel;
    while(getline(cin, line))
    {
        stringstream ss(line);
        ss >> _ >> _ >> x >> _ >> y >> _ >> _ >> vx >> _ >> vy;
        pos.emplace_back(x,y);
        vel.emplace_back(vx,vy);
    }
    int N = pos.size();
    for (int sec = 1;; ++sec)
    {
        std::vector<string> grid(H, string(101, ' '));
        
        for (int i = 0; i < N; ++i)
        {
            auto [x,y] = pos[i];
            auto [vx,vy] = vel[i];
            grid[(((y + vy * sec) % H) + H) % H][(((x + vx * sec) % W) + W) % W] = 'X';
        }

        for (auto s: grid)
        {
        	if (s.find("XXXXXXXXXX") != -1)
        	{ 
                for (auto ss: grid)
                    cout << ss << '\n';
                std::cout << "part_two: " << sec << '\n';
        		return ;
        	}
        }
        
    }
}

int main()
{
    setup();
    // part_one();
    part_two();

    return 0;
}

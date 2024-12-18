#include <iostream>
#include <stdint.h>
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
    freopen("Day08.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
// #include "debug_template.h"
#else
#define debug(...)
#endif
#include <utility>
#include <unordered_map>
#include <vector>
#include <set>

void part_one()
{
       
    unordered_map<char, vector<pair<int,int>>> antena_map;
    
    string line;
    int y = 0;
    int height,width;
    while (getline(cin, line))
    {
        for (int x = 0; x < line.length(); ++x)
        {
            char c = line[x];
            if (c != '.')
            {
                antena_map[c].push_back(make_pair(x, y));
            }
        }
        y++;
    }
    height = y;
    width = line.length();

    auto outside = [&](int x, int y) { return (x<0 or y<0 or x>=width or y >= height);};

    set<pair<int,int>> antinodes;

    for (auto &[antena, pairs]: antena_map)
    {
    	for (int i = 0; i < pairs.size(); ++i)
    	{
    	    for (int j = 0; j < pairs.size(); ++j)
            {
                if (i==j) continue;

                pair<int, int> a = pairs[i], b = pairs[j];
                
                int w = abs(a.first - b.first);
                int h = abs(a.second - b.second);

                int cx = a.first < b.first ? a.first-w : a.first+w;
                int cy = a.second < b.second ? a.second-h : a.second+h;

                int dx = b.first < a.first ? b.first-w : b.first+w;
                int dy = b.second < a.second ? b.second-h : b.second+h;

                if (not outside(cx,cy))
                    antinodes.insert({cx,cy});

                if (not outside(dx,dy))
                    antinodes.insert({dx,dy});
            }
    		 
    	}
    }

    std::cout << "part_one: " << antinodes.size() << '\n';

}

void part_two()
{
    unordered_map<char, vector<pair<int,int>>> antena_map;
    
    string line;
    int y = 0;
    int height,width;
    while (getline(cin, line))
    {
        for (int x = 0; x < line.length(); ++x)
        {
            char c = line[x];
            if (c != '.')
            {
                antena_map[c].push_back(make_pair(x, y));
            }
        }
        y++;
    }
    height = y;
    width = line.length();

    auto outside = [&](int x, int y) { return (x<0 or y<0 or x>=width or y >= height);};

    set<pair<int,int>> antinodes;

    for (auto &[antena, pairs]: antena_map)
    {
    	for (int i = 0; i < pairs.size(); ++i)
    	{
    	    for (int j = 0; j < pairs.size(); ++j)
            {
                if (i==j) continue;

                pair<int, int> a = pairs[i], b = pairs[j];
                
                int w = abs(a.first - b.first);
                int h = abs(a.second - b.second);

                // up
                int xx = a.first < b.first ? -w : w;
                int yy = a.second < b.second ? -h : h;
                int cx = a.first, cy = a.second;
                while(not outside(cx, cy))
                {
                    antinodes.insert({cx,cy}); 
                    cx += xx;
                    cy += yy;
                }
                // down
                xx = b.first < a.first ? -w : w;
                yy = b.second < a.second ? -h : h;
                int dx = b.first, dy = b.second;

                while(not outside(dx, dy))
                {
                    antinodes.insert({dx,dy}); 
                    dx += xx;
                    dy += yy;
                }
            }
    		 
    	}
    }

    std::cout << "part_two: " << antinodes.size() << '\n';
}

int main()
{
    setup();
    // part_one();
    part_two();
    return(0);
}


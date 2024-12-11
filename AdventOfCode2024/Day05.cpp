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

void part_one()
{
    int A,B;
    char _;
    string line;
    std::unordered_map<int, vector<int>> edges;
    while(1)
    {
        getline(cin, line);
        if (line == "") break;
        stringstream ss(line);
        
        ss >> A >> _ >> B;
        edges[A].push_back(B);
    }

            
    int res = 0;
    while (getline(cin, line))
    {
        // vector<int> nums = std::views::split(line, ',') | std::ranges::to<vector<int>>();

        std::vector<int> nums;
        string token;
        stringstream ss(line);
        while (getline(ss, token, ','))
            nums.push_back(stoi(token));

        set<int> earlier;
        bool ok = true;
        for (auto x: nums)
        {
            for (auto e: edges[x])
            {
            	if (earlier.count(e))
                {
                    ok = false;
                    break;   
                }
            }
            if (not ok) break;
            earlier.insert(x);
        }
        if (ok)
            res += nums[nums.size()/2];

    }
    std::cout << "res: " << res << '\n';
}


void part_two()
{
    int A,B;
    char _;
    string line;
    std::unordered_map<int, vector<int>> edges;
    while(1)
    {
        getline(cin, line);
        if (line == "") break;
        stringstream ss(line);
        
        ss >> A >> _ >> B;
        edges[A].push_back(B);
    }

            
    int res = 0;
    while (getline(cin, line))
    {
        // vector<int> nums = std::views::split(line, ',') | std::ranges::to<vector<int>>();

        std::vector<int> nums;
        std::vector<int> sorted;
        string token;
        stringstream ss(line);
        while (getline(ss, token, ','))
        {
            int x = stoi(token);
            nums.push_back(x);
            auto it = sorted.begin();

            while (it != sorted.end())
            {
                if ( std::find(edges[x].begin(), edges[x].end(), *it) != edges[x].end()) 
                    break;   
                it++;
            }
            sorted.insert(it, x);
        }
            // add mid values only if sorted values are on the same order as the originals
        if (!std::equal(sorted.begin(), sorted.end(), nums.begin())) 
            res += sorted.at(sorted.size() / 2);
        

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

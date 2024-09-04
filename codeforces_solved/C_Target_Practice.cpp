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

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    s64 t;
    cin >> t;

    while(t--)
    {
        std::vector<std::string> targets(10);
        for (auto &e: targets)
        	cin >> e;

        int x=0,X=9,y=0,Y=9;
        int res = 0;
        for (int r = 0; r < 10; ++r)
        {
            for (int c = 0; c < 10; ++c)
            {
                if (targets[r][c]=='X')
                {
                    int point = min(min(r, 9-r), min(c, 9-c)) +1;
                    res += point;
                }
            }
        }
        std::cout << res << '\n';
    }
 
    return 0;
}

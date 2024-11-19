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

int main()
{
    setup();

    int t, l, r, c;
    cin >> t;

    while(t--)
    {
        cin >> l >> r >> c;

        std::vector<int> left(l);
        std::vector<int> right(r);

        for (auto &e: left)
        	cin >> e;
        for (auto &e: right)
        	cin >> e;

        int res = 0;

        for (auto a: left)
        {
        	for (auto b: right)
        	{
        		if ( (a+b) <= c)
                    res++;
        	}
        }
        std::cout << res << '\n';
        
    }
 
    return 0;
}

// https://codeforces.com/contest/1941/problem/A
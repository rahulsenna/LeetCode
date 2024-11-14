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

    s64 t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        std::vector<int> pass(n);
        for (auto &e: pass)
        	cin >> e;

        std::vector<bool> neigb(2*10e5, 0);
        neigb[pass[0]] = true;

        bool res = true;
        for (int i = 1; i < n; ++i)        
        {
            auto e = pass[i];

            if (neigb[e+1] or neigb[e-1])
                neigb[e] = true;
            else
            {
                res = false;
                break;
            }
        }
        cout << (res? "YES\n": "NO\n");
        
    }
    return 0;
}

// https://codeforces.com/contest/2000/problem/B
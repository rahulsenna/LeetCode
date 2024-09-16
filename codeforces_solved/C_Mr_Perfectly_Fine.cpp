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

    s64 t,n;
    cin >> t;
    
    while(t--)
    {
        cin >> n;

        s64 time;
        string skill;
        s64 x01 = INT_MAX, x10 = INT_MAX, x11 = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            cin >> time >> skill;
            if (skill == "11") x11 = min(x11, time);
            if (skill == "01") x01 = min(x01, time);
            if (skill == "10") x10 = min(x10, time);
        }
        
        s64 res = min(x11, x01+x10);
        if (res == INT_MAX) res = -1;

        cout << res << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1829/problem/C
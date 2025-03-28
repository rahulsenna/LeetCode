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

    int t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        
        int robin = 0;
        int res = 0;
        int gold;
        for (int i = 0; i < n; ++i)
        {
            cin >> gold;
            if (gold >= k)
                robin += gold;

            if (gold == 0 && robin)
                robin--, res++;
        }
        
        std::cout << res << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/2014/problem/A
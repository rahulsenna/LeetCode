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

    s64 t;
    cin >> t;
    int n;
    char c;
    while(t--)
    {
        int curr = 1;
        int res = 0;
        for (int i = 0; i < 4; ++i)
        {
            cin >> c;
            n = (c-'0');
            if (n == 0)
                n = 10;
            res += abs(n-curr)+1;
            curr = n;
        }
        std::cout << res << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/1883/problem/A
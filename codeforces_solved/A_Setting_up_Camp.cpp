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

    s64 t, a, b, c;
    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;

        s64 ans = a;

        if (b%3==0)
        {
            ans += (b/3) + ceil(c/3.);
            std::cout << ans << '\n';
            continue;
        }

        s64 rem =  ((b/3 +1)*3) - b;

        if (rem > c)
        {
            cout << "-1\n";
            continue;
        }

        b += rem;
        c -= rem;

        ans += (b/3) + ceil(c/3.);
        std::cout << ans << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1945/problem/A


// One liner 
// cout << (c < (3 - b % 3) % 3 ? -1 : a + (b + c + 2) / 3) << "\n";
#include <bits/stdc++.h>
using namespace std;

typedef int64_t     s64;
typedef uint64_t    u64;
typedef long double r64;

inline void setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

    s64 t, n, k, x;
    cin >> t;

    while (t--)
    {
        cin >> n >> k >> x;
        s64 total = n * (n + 1) / 2;
        s64 m     = n - k;
        s64 mtot  = m * (m + 1) / 2;
        s64 mins  = k * (k + 1) / 2;
        s64 maxs  = total - mtot;

        if (x <= maxs and x >= mins)
            std::cout << "YES\n";
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
// https://codeforces.com/contest/1878/problem/C

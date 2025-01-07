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
        std::vector<s64> a(n);
        
        s64 sum_even = 0, sum_odd = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i&1)
                sum_odd += a[i];
            else
                sum_even += a[i];
        }

        s64 cnt_even = n/2, cnt_odd = n/2;
        if (n&1)
            cnt_even++;

        if (sum_odd % cnt_odd != 0 or sum_even % cnt_even != 0 or (sum_odd/cnt_odd) != (sum_even/cnt_even))
            std::cout << "NO" << '\n';
        else
            std::cout << "YES" << '\n';

    }
 
    return 0;
}
// https://codeforces.com/contest/2050/problem/B
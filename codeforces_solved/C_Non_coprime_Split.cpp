#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif




s64 prime(s64 n)
{
    for (s64 i = 3; i * i <= n; i+=2)
    {
        if (n % i == 0)        
            return i;
    }
    return n;
}

void solve()
{
    s64 l, r;
    cin >> l >> r;

    if (r <= 3)
    {
        cout << "-1\n";
        return;
    }

    if (l<r)
    {
        if (r & 1)
            r--;
        cout << 2 << " " << r - 2 << '\n';
        return;
    }

    if (not(r&1))
    {
        cout << 2 << " " << r - 2 << '\n';
        return;
    }

    auto p = prime(r);
    if (p==r)
    {
        cout << "-1\n";
        return;   
    }
    cout << p << " " << r-p << '\n';
}
int main()
{
    setup();

    // primes = seive(10e7+1);

    s64 t,l,r;
    cin >> t;

    while(t--)
    {
        solve();
    }
 
    return 0;
}
// https://codeforces.com/contest/1872/problem/C
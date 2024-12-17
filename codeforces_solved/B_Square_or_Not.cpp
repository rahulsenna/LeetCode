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

void solve()
{
    s64 n;
    string s;

    cin >> n >> s;
    s64 sq = sqrt(n);
    
    if ((sq*sq) != n)
    {
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < sq; ++i)
    {
        for (int j = 0; j < sq; ++j)
        {
            bool on_edge = i==0 or i==(sq-1) or j==0 or j==(sq-1);
            if (on_edge and s[sq*i+j] != '1')
            {
                cout << "No\n";
                return;
            }

            if (not on_edge and s[sq*i+j] != '0')
            {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
}

int main()
{
    setup();
    s64 t;
    cin >> t;
    
    while(t--)
        solve();
 
    return 0;
}

// https://codeforces.com/contest/2008/problem/B
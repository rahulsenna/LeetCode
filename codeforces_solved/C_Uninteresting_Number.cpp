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
// #include "debug_template.h"
#else
#define debug(...)
#endif

void solve()
{
    string s;

    cin >> s;
    s64 sum = 0;
    int two_cnt = 0, three_cnt=0;
    for (auto c: s)
    {
        s64 d = c - '0';
        sum+=d;
        if (d==2)two_cnt++;
        if (d==3)three_cnt++;
    }
    int x_cnt = min(8,two_cnt);
    int y_cnt = min(8,three_cnt);
    for (int x = 0; x <= x_cnt; ++x)
    {
        for (int y = 0; y <= y_cnt; ++y)
        {
            if ((2*x+6*y+sum)%9==0)
            {
                std::cout << "YES\n";
                return;        
            }
        }
    }
        
    std::cout << "NO\n";
}

int main()
{
    setup();

    s64 t;
    cin >> t;
    while(t--)
    {
        solve();
    }
 
    return 0;
}
// https://codeforces.com/contest/2050/problem/C
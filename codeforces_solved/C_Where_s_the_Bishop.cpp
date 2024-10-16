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

    while(t--)
    {
        string s;
        int r=-1,c=-1;
        for (int row = 0; row <= 7; ++row)
        {
        	 cin >> s;
             if (r!=-1)
                continue;
             for (int col = 0; col <= 5; ++col)
             {
             	 if (s[col]=='#' && s[col+1]=='.' && s[col+2]=='#')
                    r = row+2, c = col+2;
             }
        }
        cout << r << ' ' << c << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1692/problem/C
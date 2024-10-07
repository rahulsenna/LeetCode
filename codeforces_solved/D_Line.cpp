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

    s64 t, n;
    cin >> t;
    string str;
    while(t--)
    {
        cin >> n >> str;
        int m = (n)/2;
        int mm = m;
        if (n%2!=0)
            mm++;

        s64 res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == 'L')
                res += i;
            else
                res += (n - (i+1));            
        }

        int l = 0, r = n - 1;

        for (int k = 1; k <= n; ++k)
        {
            while (str[l] == 'R' && l < m) l++;   // skip if already optimal direction
            while (str[r] == 'L' && r >= mm) r--; // skip if already optimal direction

            if (l<m && (n-1-l >= r))
            {
                res -= l;
                res += (n-1-l);
                l++;
            } else if (r>=mm)
            {
                res -= (n-r-1);
                res += (r);
                r--;
            }
            cout << (res) << " ";
        }

        cout << '\n';


    }
 
    return 0;
}

// https://codeforces.com/contest/1722/problem/D
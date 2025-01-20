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

int main()
{
    setup();

    int t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;

        int res = INT_MAX, d, s;
        for (int i = 0; i < n; ++i)
        {
        	cin >> d >> s;
            res = min(res, d+(s-1)/2);
        }
        std::cout << res << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/1872/problem/B
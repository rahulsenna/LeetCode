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

    int t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        std::vector<int> a(n);
        bool res = false;
        for (auto &e: a)
        {
        	cin >> e;
            if (e == k)
                res = true;
        }

        cout << (res ? "YES\n" : "NO\n");
    }
 
    return 0;
}
// https://codeforces.com/contest/1878/problem/A
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

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    s64 t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        std::vector<s64> arr = {LONG_MAX};
        s64 e,b=-1;
        for (int i = 0; i < n; ++i)
        {
            cin >> e;
            if (e!=b)
                arr.emplace_back(e);
            b = e;
        }
        arr.emplace_back(LONG_MAX);

        int valley_cnt = 0;
        bool res = true;
        for (int i = 2; i < arr.size(); ++i)
        {
            auto l = arr[i - 2], m = arr[i - 1], r = arr[i];
            if (l > m && r > m)
                valley_cnt++;
            
            if (valley_cnt>1)
            {
                res = false;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';

    }
    return 0;
}

// https://codeforces.com/contest/1760/problem/D
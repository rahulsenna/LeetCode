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

    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;

        std::vector<std::vector<int>> mountains(n, std::vector<int>(n));
        vector<int> ans(2*n, 0);
        for (int i = 0; i < n; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
                cin >> mountains[i][j];
                int diff = (j - i) + (n-1);
                ans[diff] = max(ans[diff], -mountains[i][j]);
        	} 
        }

        int magic = accumulate(ans.begin(), ans.end(),0);
        std::cout << magic << '\n';
    }   
 
    return 0;
}

// https://codeforces.com/contest/2033/problem/B
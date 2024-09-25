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

    string s;
    s64 T = 1;
    while(t--)
    {
        cin >> n >> s;

        vector<int> A(26, 0), B(26, 0);
        for(auto c: s) B[c - 'a']++;
        
        int res = 0;
        for(auto c: s)
        {
            ++A[c - 'a'];
            --B[c - 'a'];
            
            int cur = 0;
            for (int i = 0; i < 26; ++i)
            {
                auto a = min(1, A[i]);
                auto b = min(1, B[i]);
                cur += a + b;
            }
            res = max(res, cur);
    }

        std::cout << res << '\n';
    }
 
    return 0;
}

// wrong answer 160th numbers differ - expected: '9', found: '8'
// https://codeforces.com/contest/1791/problem/D

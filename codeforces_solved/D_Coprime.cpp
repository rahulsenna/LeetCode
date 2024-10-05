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


std::vector<int> coprimes[1001];

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout),freopen("error.txt", "w", stderr);
#endif

    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
        {
            if (std::gcd(i,j)==1)
                coprimes[i].push_back(j);
        }
    }
    

    s64 t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int idx[1001];
        fill_n(idx, 1001, -1);
        
        int e;
        for (int i = 1; i <= n; ++i)
        {
            cin >> e;
            idx[e] = i;
        }

        int ans = -1;
        for (int i = 1; i <= 1000; ++i)
        {
            if (idx[i] == -1)
            	continue;
            
            for (int j: coprimes[i])
            {
                if (idx[j] != -1)
                ans = max(ans, idx[i]+idx[j]);
            }
        }

        std::cout << ans << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1742/problem/D
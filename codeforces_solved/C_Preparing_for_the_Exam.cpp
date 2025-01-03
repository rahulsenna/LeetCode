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

    s64 t,n,m,k;
    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;
        std::vector<int> M(m);
        for (auto &e: M)
        	cin >> e;        

        int missing = 0;

        for (int x = 1; x <= n; x++)
            missing ^= x;

        std::vector<int> K(k);
        for (auto &e: K)
        {
            cin >> e;
            missing ^= e;
        }
        	
        if (n==k)
        {
            cout << string(m, '1') << '\n';
            continue;
        }
        if (n-1>k)
        {
            cout << string(m, '0') << '\n';
            continue;
        }

        for (auto &e: M)
        	cout << (missing==e);
        
        
        cout << '\n';        
    }
 
    return 0;
}
// https://codeforces.com/contest/2051/problem/C
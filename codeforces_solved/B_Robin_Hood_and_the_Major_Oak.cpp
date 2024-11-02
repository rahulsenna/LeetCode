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

    s64 t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        int odds = 0;

        auto N = (n - (k - 1));
        s64 nums = n-N;

        if (n % 2 != 0)
            odds++;
        else
            nums +=1;
        
        if (N != n)
            odds += nums/2;
            
    
        if (odds % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}

// https://codeforces.com/contest/2014/problem/B


#if  0 // Another method

// This can be done by finding the sum of n−k+1,n−k+2,...,n−1,n
//  which is k∗(2n−k+1)/2

int main()
{
    setup();

    s64 t, n, k;
    cin >> t;

    while(t--)
    {
        int64_t n, k;
        cin >> n >> k;
        int64_t ans = (n + 1) / 2 - (n - k + 1) / 2;
        cout << (ans % 2 == 0 ? "YES" : "NO") << '\n';
    }
}
#endif  //0 // Another method
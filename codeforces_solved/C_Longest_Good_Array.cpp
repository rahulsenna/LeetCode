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

    s64 t,l,r;
    cin >> t;

    while(t--)
    {
        cin >> l >> r;

        s64 cnt = 0;
        s64 inc = 1;

        // brute force
        while(l<=r)
        {
            if (cnt>=1)
                inc++;
            l += inc;

            cnt++;
        }
        std::cout << cnt << '\n';
    }
 
    return 0;
}


/* 
// binary search

We can solve this problem greedily. Let's choose the first element equal to l
. Then, the second element should be l+1
. The third l+3
, and so on. In general, the i−
th element is equal to l+i⋅(i+1)/2
.


while(l<r)
{
    long long m=(l+r)/2;
    if(m*(m-1)/2<=b)
    {
        l=m+1;
    }
    else
    {
        r=m;
    }
}
cout<<l-1<<endl;
 */

// https://codeforces.com/contest/2008/problem/C
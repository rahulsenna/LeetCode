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

    while(t--)
    {
        cin >> n;
        std::vector<s64> golds(n);
        
        s64 gold_sum = 0;
        s64 max_g = 0;
        for (auto &e: golds)
        {
            cin >> e;
            gold_sum += e;
            if (e>max_g)
                max_g = e;
        }
        	

        if (n<=2)
        {
            cout << -1 << '\n';
            continue;
        }

        ranges::sort(golds);

        cout << max(0LL,((golds[n/2]*2*n)-gold_sum)+1) << '\n';

        // gold At [idx n/2] should be less than (gold_sum+x / n*2)
        // so: x = gold[idx n/2]*n*2 - gold_sum +1;
        // +1 because we want half avg to be bigger than gold at [idx n/2]


#if  0 // binary search not working, test case #3 fails
        auto unhappy = (golds[n/2]);

        s64 l =0, r = n*2LL*max_g;

        r64 n2 = r64(1) / (n * 2LL);
        s64 ans = 0;
        while(l<r)
        {
            s64 m = (r+l)/2LL;

            if (ceil(r64(gold_sum+m)*n2)> unhappy)
                r = m;
            else
                l = (m+1LL);
        }
        ans = l;
        while (ans && (ceil(r64(gold_sum+ans-1LL)*n2))> unhappy)
        {
            ans--;
        }

        cout << ans << '\n';

#endif  //0 // binary search not working, test case #3 fails



        
    }
 
    return 0;
}


// https://codeforces.com/contest/2014/problem/C
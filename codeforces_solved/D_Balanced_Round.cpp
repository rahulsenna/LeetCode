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

    s64 t,n,k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        std::vector<int> problems(n);
        for (auto &p: problems)
            cin >> p;

        ranges::sort(problems);

        int biggest = 0;
        int streak = 0;

        for (int idx = 1; idx < n; ++idx)
        {
            if (problems[idx] - problems[idx-1] <= k)
                streak++;
             else
                streak = 0;
            
            biggest = max(biggest, streak);
        }

        std::cout << n-(biggest+1) << '\n';
        
    }
 
    return 0;
}

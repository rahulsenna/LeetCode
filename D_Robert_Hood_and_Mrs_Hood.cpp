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

    s64 t, n, d, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> d >> k;

        std::vector<int> jobs(n+1);
        fill(jobs.begin(), jobs.end(), 0);

        int a,b;
        int x=1,y=1;
        int maxJ = 0;
        for (int i = 0; i < k; ++i)
        {
        	 cin >> a >> b;

            for (int j = a; j <= b; ++j)
            {
                jobs[j]++;
                if (jobs[j]> maxJ)
                { 
                	maxJ = jobs[j];
                    x = j;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            int j = i;
            while (jobs[j++] == 0);
            if ((j-i) > d)
            {
                y = i;
                break;
            }
        }

        cout << x << " " << y << "\n";
    }
 
    return 0;
}

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
// #include "debug_template.h"
#else
#define debug(...)
#endif

int main()
{
    setup();

    s64 t,n,x,y;
    cin >> t;

    while(t--)
    {
        cin >> n >> x >> y;
        std::vector<s64> A(n);
        s64 sum = 0;
        for (auto &e: A)
        {
        	cin >> e;
            sum += e;
        }
        if (sum < x)
        {
            cout << "0\n";
            continue;
        }
        ranges::sort(A);
        
        if (A[0]>y)
        { 
            cout << "0\n";
            continue;
        }


        s64 res = 0;
        for (int i = 0; i < n; ++i)
        {
            s64 remaining = sum - A[i];
            int j1 = -1, j2 = -1;

            int l = i + 1, r = n - 1;
            while (l <= r) // push left
            {
                int mid = (l + r) / 2;
                if (remaining - A[mid] >= x and remaining - A[mid] <= y)
                {
                    j1 = mid;
                    r = mid - 1;
                }
                else if (remaining - A[mid] < x)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            l = max(j1,i+1), r = n - 1;
            while (l <= r) // push right
            {
                int mid = (l + r) / 2;
                if (remaining - A[mid] >= x and remaining - A[mid] <= y)
                {
                    j2 = mid;
                    l = mid + 1;
                }
                else if (remaining - A[mid] < x)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (j1 != -1 and j2 != -1)
            {
                res += (j2 - j1) + 1;
            }

        }
        std::cout << res << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/2051/problem/D

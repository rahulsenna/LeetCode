#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
    s64 t,n,m, M;
    cin >> t;
    int T = 0;
    while(t--)
    {
        cin >> n >> m;
        std::vector<s64> nums(n);
        for (auto &e: nums)
        	cin >> e;

        cin >> M;

        s64 prev = INT64_MIN;
        for (auto &e: nums)
        {
            auto new_e = M-e;

            if (e < prev || new_e < e && new_e >= prev)
                e = new_e;

            if (prev > e)
            {
                cout << "NO\n";
                goto end;
            }
            prev = e;
        }        
        cout << "YES\n";
end:            

    }
 
    return 0;
}
// https://codeforces.com/contest/2065/problem/C1
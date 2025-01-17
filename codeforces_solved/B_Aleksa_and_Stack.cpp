#include <bits/stdc++.h>
using namespace std;

typedef int64_t     s64;
typedef uint64_t    u64;
typedef long double r64;

inline void setup()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

    while (t--)
    {
        cin >> n;
        debug(n);
        vector<s64> nums(n);
        nums[0] = 1;
        nums[1] = 3;
        for (int i = 2; i < n; ++i)
        {
            s64 next = nums[i - 1] + 1;
            debug(next);
            auto prevsum = nums[i - 1] + nums[i - 2];
            while ((nums[i - 1] + next) % 3 == 0 or next % prevsum == 0)
            {
                next++;
            }
            nums[i] = next;
        }
        for (auto e : nums)
        {
            cout << e << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
// https://codeforces.com/contest/1878/problem/B
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

void solve()
{
    
    std::vector<s64> num(3);
    cin >> num[0] >> num[1] >> num[2];
    ranges::sort(num);
    auto a = num[0], b = num[1], c = num[2];

    if (b%a != 0 or c%a!=0)
    {
        cout << "NO\n";
        return;
    }

    int ops = 0;
    int A = a;
    while (A<b)
    {
        A+=a;
        ops++;
        if (ops > 3)
            break;
    }
    A = a;
    while (A<c)
    {
        A+=a;
        ops++;
        if (ops > 3)
            break;
    }
    if (ops <=3)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    setup();

    s64 t;
    cin >> t;

    while(t--)
    {
        solve();
    }
 
    return 0;
}
// https://codeforces.com/contest/1881/problem/B
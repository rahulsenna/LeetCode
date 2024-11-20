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

    s64 t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        std::vector<int> nums(n);
        std::vector<int> ones;
        std::vector<int> twos;
        int sum = 0;
        for (auto &e: nums)
        {
        	cin >> e;
            sum+=e;
            if (e%3==1)
                ones.push_back(e);
            else if (e%3==2)
                twos.push_back(e);
            else
                n--;
        }

        int rem = sum%3;

        if (rem == 0)
        {
            cout << "0\n";
            continue;
        }
        
        if (rem == 2 or (rem == 1 and not ones.empty()) or (rem == 2 and not twos.empty()))
        {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
        
    }
 
    return 0;
}

// https://codeforces.com/contest/1933/problem/B
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

    int t,n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        std::vector<int> candies(n);
        for (auto &e: candies)
        	cin >> e;


        int alice_curr = 0, bob_curr = 0;
        int alice = 0, bob = 0, moves = 0;

        int l = 0, r = n-1;
        while(l<=r)
        {
            if (alice_curr <= bob_curr)
            {
                while(l<=r && alice_curr<=bob_curr)
                {
                    alice_curr += candies[l];
                    l++;
                }
                alice += alice_curr;
                bob_curr = 0;
            } else
            {
                while(l<=r && bob_curr<=alice_curr)
                {
                    bob_curr += candies[r];
                    r--;
                }
                bob += bob_curr;
                alice_curr = 0;
            }

            moves++;
        }

        cout << moves << " " << alice << " " << bob << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1352/problem/D
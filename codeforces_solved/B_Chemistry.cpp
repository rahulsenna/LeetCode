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

int main()
{
    setup();

    int t,n,k;
    cin >> t;
    string s;
    while(t--)
    {
        std::vector<int> map(26,0);
        cin >> n >> k >> s;
        
        if (n-k ==1)
        {
            std::cout << "YES" << '\n';
            continue;
        }

        for (auto c: s)
        	map[c-'a']++;

        int odd_cnt = 0;
        for (auto cnt: map)
        {
        	if (cnt&1)
                odd_cnt++;
        }
        n-=k;
        odd_cnt-=k;
        
        if (odd_cnt < 0)
        {
            if (abs(odd_cnt)&1)
                odd_cnt = 1;
            else
                odd_cnt = 0;
        }

        if ((odd_cnt == 0) or (n & 1 and odd_cnt <= 1))
        {
            std::cout << "YES" << '\n';
        } else
        {
            std::cout << "NO" << '\n';
        }
    }
 
    return 0;
}

// https://codeforces.com/contest/1883/problem/B
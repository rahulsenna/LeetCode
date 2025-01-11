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


int solve()
{
    int n,k;
    cin >> n >> k;
    std::vector<int> nums(n);
    int even_cnt = 0;
    bool multiple_found = false;
    for (auto &e : nums)
    {
        cin >> e;
        even_cnt += not(e & 1);
        if (e%k==0)
            multiple_found = true;
    }

    if (multiple_found)
        return 0;
    
    if (k == 2)
        return  not even_cnt;
    
    if (k == 4) // need two even ints or one multiple of 4
    {
        if (even_cnt>=2)
            return 0;
        
        int res = 2;
        if (even_cnt == 1)
            res = 1;
        for (auto e: nums)
            res = min(res, 4-e%4);
        return res;
    }
    int res = INT_MAX;
    for (auto e: nums)
        res = min(res, k - e % k);
    
    return(res);
}

int main()
{
    setup();

    int t;
    cin >> t;

    while(t--)
    {
        cout << solve() << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/1883/problem/C
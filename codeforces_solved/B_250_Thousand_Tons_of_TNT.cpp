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
        vector<s64> trucks(n);
        for (auto &e: trucks)        
            cin >> e;

        vector<s64> trucks_t = trucks;
        ranges::sort(trucks_t);

        s64 max_diff = trucks_t.back() - trucks_t.front();

        vector<int64_t> prefix_sum(trucks.size() + 1, 0);
 
        for (int i = 0; i < trucks.size(); i++)
            prefix_sum[i + 1] = prefix_sum[i] + trucks[i];

        int N = trucks.size()/2;

        for (int k = 2; k <= N; ++k)         
        {
            while (trucks.size() % k != 0)
                k++;
            
            vector<s64> temp;
            for (int x = 0; x < trucks.size(); x += k)
            {
                s64 sum = 0;
                for (int y = x; y < (x + k) and y < trucks.size(); ++y)
                    sum += trucks[y];
                
                temp.push_back(sum);
            }

            ranges::sort(temp);
            auto diff = temp.back()-temp.front();
            max_diff = max(max_diff, diff);
        }
        cout << max_diff << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1899/problem/B

#if  0 // Neal's code (prefix sum)

void run_case() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
 
    for (auto &a : A)
        cin >> a;
 
    vector<int64_t> prefix_sum(N + 1, 0);
 
    for (int i = 0; i < N; i++)
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
 
    int64_t ans = 0;
 
    for (int k = 1; k < N; k++)
        if (N % k == 0) {
            int64_t least = INF64, most = 0;
 
            for (int i = 0; i < N; i += k) {
                int64_t sum = prefix_sum[i + k] - prefix_sum[i];
                least = min(least, sum);
                most = max(most, sum);
            }
 
            ans = max(ans, most - least);
        }
 
    cout << ans << '\n';
}
#endif  //0 // Neal's code (prefix sum)
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

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif


std::vector<int> rem(200001);
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    s64 t,n;
    cin >> t;

    int N = 200000;
    s64 sum = 0;
    do
    {
        rem[N] = sum;
        int nn = N;
        while(nn)
        {
            sum += nn %10;
            nn /= 10;
        }

    } while(N--);


    while(t--)
    {
        cin >> n;
        int res = sum - rem[n];
        std::cout << res << '\n';
    }
 
    return 0;
}

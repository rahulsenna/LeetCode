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

    s64 t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        s64 kk = k;
        int div = k/n;
        while(1)
        {
            kk = k+ kk/n;
            if (div == kk/n)
                break;
            div = kk/n;
        }
        std::cout << kk << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/1352/problem/C


#if  0 // Using Binary Seach ( NEAL's code)
void run_case() {
    int64_t N, K;
    cin >> N >> K;
    int64_t low = 0, high = 2 * K;
 
    while (low < high) {
        int64_t mid = (low + high) / 2;
 
        if (mid - mid / N >= K)
            high = mid;
        else
            low = mid + 1;
    }
 
    cout << low << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests;
    cin >> tests;
 
    while (tests-- > 0)
        run_case();
}

#endif  //0 // Using Binary Seach ( NEAL's code )



#if 0 // Using math ( casul's code )
int main()
{
    int t;
	cin >> t;
	while (t--)
    {
		int n, k;
		cin>>n>>k;
		int need=(k-1)/(n-1);
		cout<<k+need<<'\n';
	}
    return 0;
}
#endif  //0 // Using math ( casul's code )
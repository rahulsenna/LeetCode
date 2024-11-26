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

    s64 t;
    cin >> t;

    while(t--)
    {
        int a,b,c,d,x,y,z,w;

        cin >> a >> x >> b >> y >> c >> z >> d >> w;
        int res = 0;
        if (a==b)
        {
            res = abs(x-y);
            res *= abs(z-w);
        } else if (a==c)
        {
            res = abs(x-z);
            res *= abs(y-w);
        } else
        {
            res = abs(x-w);
            res *= abs(z-y);
        }

        std::cout << res << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1921/problem/A

#if  0 //

void solve() {
	int mn = 1e9, mx = -1e9;
	for (int i = 0; i < 4; ++i) {
		int x = nxt();
		mn = min(mn, x);
		mx = max(mx, x);
		nxt();
	}
	cout << (mx - mn) * (mx - mn) << "\n";
}
#endif  //0 //
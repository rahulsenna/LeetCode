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

    s64 t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int cur = 0;
        while( n--)
        {
            int e; cin >> e;
            cur += e - cur % e;
        }
        std::cout << cur << '\n';
    }
 
    return 0;
}
// https://codeforces.com/contest/1932/problem/B

#if  0 // tourist's code

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans = (ans / a + 1) * a;
    }
    cout << ans << '\n';
  }
  return 0;
}
#endif  //0 // 
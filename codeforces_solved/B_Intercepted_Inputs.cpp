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
        int nums = n-2;

        std::set<int> divs;
        std::vector<int> digs(n);
        for (auto &e: digs)
        	cin >> e;
        
        
        for (auto &e: digs)
        {

            if (nums%e ==0)
            {
                for (auto h: divs)
                {
                	if (e*h == nums)
                	{ 
                        cout << e << " " << h << "\n";
                        goto end;
                	}
                }
                divs.insert(e);
            }
        }
        end:

    }
 
    return 0;
}

// https://codeforces.com/contest/2037/problem/B


#if  0 // tourist's code
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }
    for (int x = 1; x <= n; x++) {
      if (cnt[x] > 0 && (n - 2) % x == 0) {
        if (cnt[(n - 2) / x] > 0) {
          cout << x << " " << (n - 2) / x << '\n';
          break;
        }
      }
    }
  }
  return 0;
}
#endif  //0 // touris
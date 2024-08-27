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

    while(t--)
    {
        cin >> n;
        std::vector<std::string> str(n);
        for (auto &e: str)
        	cin >> e;
        
        string res = "SQUARE\n";
        int c = 0;
        for (auto &s: str)
        {
            int cc = count(s.begin(), s.end(), '1');
            if (cc != 0 && c != 0 && c != cc)
            {
                res  = "TRIANGLE\n";
                break;
            } else
            {
                c = cc;
            }
        }
        
        cout << res;
        
    }
 
    return 0;
}

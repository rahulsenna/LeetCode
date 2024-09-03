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

    s64 t;
    std::string s;
    cin >> t;

    while(t--)
    {
        char res = 'A'^'B'^'C';
        for (int i = 0; i < 3; ++i)
        {
        	cin >> s;
            if (s.find('?') != -1)
            { 
                for (auto &e: s)
                {
                    if (e!='?')
                        res ^= e;
                }
            }
        }
        std::cout << res << '\n';
    }
 
    return 0;
}
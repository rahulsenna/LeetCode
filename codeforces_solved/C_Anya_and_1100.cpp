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

    string s;

    auto is1100 = [&](int i)
    {
        if (i<0 or i >= (s.length()-3))
            return 0;

        if (s[i]=='1' and s[i+1]=='1' and s[i+2] == '0' and s[i+3]=='0')        
            return 1;
         else 
            return 0;
    };

    while(t--)
    {
        int i;
        char v;

        cin >> s >> n;
        int count1100 = 0;
        for (int i = 0; i < s.length(); ++i)
        	 count1100 += is1100(i);
        
        

        for (int x = 0; x < n; ++x)
        {
            cin >> i >> v;
            i--;
            
            if (s[i] == v)
            {   
                cout << (count1100 ? "YES\n" : "NO\n");
                continue;
            }

            int before = is1100(i-3) or is1100(i-2) or is1100(i-1) or is1100(i);
            s[i] = v;
            int after = is1100(i-3) or is1100(i-2) or is1100(i-1) or is1100(i);

            count1100 += (after - before);
            
            cout << (count1100 ? "YES\n" : "NO\n");
            
        }
    }
 
    return 0;
}

// https://codeforces.com/contest/2036/problem/C
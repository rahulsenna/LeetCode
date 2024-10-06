#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

inline void setup() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

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
    setup();

    s64 t, n;
    string str;
    cin >> t;

    while(t--)
    {
        cin >> n;
        std::unordered_map<string,int> words;
        vector<string> wrds[3];
        for (int i = 0; i < 3; ++i)
        {
        	 for (int j = 0; j < n; ++j)
        	 {
        	 	 cin >> str;
                 words[str]++;
                 wrds[i].emplace_back(str);
        	 }
        }

        for (int i = 0; i < 3; ++i)
        {
            int res = 0;

            for (auto e: wrds[i])
            {
                int cnt = words[e];
                if (cnt == 1)
                    res += 3;
                else if (cnt == 2)
                    res += 1;            	
            }
            cout << res << " ";
        }
        cout << '\n';


    }
 
    return 0;
}

// https://codeforces.com/contest/1722/problem/C
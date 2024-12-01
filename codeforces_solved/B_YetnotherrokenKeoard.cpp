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
    string s;
    while(t--)
    {
        cin >> s;
        std::vector<int> low;
        std::vector<int> upp;

        for (int i = 0; i < s.length(); ++i)
        {
        	if (s[i] == 'b')
            {
                if  (not low.empty())
                    low.pop_back();
                continue;
            }
            if (s[i] == 'B')
            {
                if (not upp.empty())
                    upp.pop_back();
                continue;
            }

            if (isupper(s[i]))
                upp.push_back(i);
            else
                low.push_back(i);
            
        }

        int i =0,j=0;
        string out = "";
        while(i < low.size() and j < upp.size())
        {
            if (low[i] < upp[j])
            {
                out += s[low[i]];
                i++;
            } else 
            {
                out += s[upp[j]];
                j++;
            }
        }

        if (i < low.size())
        {
            for (int x = i; x < low.size(); ++x)
            	 out += s[low[x]];
        } else
        {
            for (int x = j; x < upp.size(); ++x)
            	 out += s[upp[x]];
        }

        std::cout << out << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1907/problem/B
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

    string t;
    cin >> t;

    int n = t.length();
    
    // For each possible length of original string
    for (int len = (n + 1) / 2; len < n; len++) 
    {
        string potential = t.substr(0, len);
        
        // Try all possible overlap lengths
        for (int overlap = 1; overlap < len; overlap++) 
        {
            // Calculate where second string should start
            int secondStart = len - overlap;
            
            // First part (up to overlap)
            string constructed = potential.substr(0, secondStart);
            
            // Check if overlap matches in both strings
            string overlap1 = potential.substr(secondStart, overlap);
            string overlap2 = potential.substr(0, overlap);
            if (overlap1 != overlap2) continue;
            
            // Add second string
            constructed += potential;
            
            if (constructed == t) 
            {
                cout << "YES\n" << potential << "\n";
                goto END;
            }
        }
    }


    cout << "NO\n";
END:
    return 0;
}

// https://codeforces.com/contest/2010/problem/C1
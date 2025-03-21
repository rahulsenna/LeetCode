#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
        auto it = adjacent_find(s.begin(), s.end());
        
        if (it == s.end())
            cout << s.length() << '\n';
        else
            cout << 1 << '\n';
        
    }
 
    return 0;
}

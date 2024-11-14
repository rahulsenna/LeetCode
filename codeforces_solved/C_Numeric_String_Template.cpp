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

    s64 t,n,m;
    cin >> t;

    while(t--) 
    {
        cin >> n;
        vector<s64> nums(n);
        for (auto& e : nums) cin >> e;

        cin >> m;
        string s;
        while (m--) {
            cin >> s;
            if (s.size() != n) 
            {
                cout << "NO\n";
                continue;
            }

            unordered_map<s64, char> num_to_char;
            unordered_map<char, s64> char_to_num;
            bool valid = true;

            for (int i = 0; i < n && valid; ++i)
            {
                char c = s[i];
                s64 num = nums[i];

                if (!num_to_char.count(num) && !char_to_num.count(c)) {
                    num_to_char[num] = c;
                    char_to_num[c] = num;
                }
                else if (num_to_char[num] != c ||
                    (char_to_num.count(c) && char_to_num[c] != num)) {
                    valid = false;
                }
            }

            cout << (valid ? "YES\n" : "NO\n");
        }
}
 
    return 0;
}

// https://codeforces.com/contest/2000/problem/C
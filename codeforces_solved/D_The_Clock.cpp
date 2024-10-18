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

    bool map[1440];
    fill_n(map, 1440, 0);

    map[0] = 1;
    map[70] = 1;
    map[140] = 1;
    map[210] = 1;
    map[280] = 1;
    map[350] = 1;
    map[601] = 1;
    map[671] = 1;
    map[741] = 1;
    map[811] = 1;
    map[881] = 1;
    map[951] = 1;
    map[1202] = 1;
    map[1272] = 1;
    map[1342] = 1;
    map[1412] = 1;
        
    int x, h, m;
    char _;
    while(t--)
    {
        cin >> h >> _ >> m >> x;
        int curr = (h*60+m);
        int start = curr;
        int res =0;
        do
        {
        	if (map[curr])
        		res++;
        	 
            curr+=x;
            curr %= 1440;
            
        } while(curr != start);
        
        std::cout << res << '\n';
    }
 
    return 0;
}

// https://codeforces.com/contest/1692/problem/D


#if  0 // jiangly's solution
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int x;
    std::cin >> x;
    
    x = std::gcd(x, 1440);
    
    int t = std::stoi(s.substr(0, 2)) * 60 + std::stoi(s.substr(3));
    t %= x;
    
    int ans = 0;
    for (int i = t; i < 1440; i += x) {
        int a = i / 600;
        int b = i / 60 % 10;
        int c = i / 10 % 6;
        int d = i % 10;
        
        if (a == d && b == c) {
            ans++;
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

#endif  //0 // jiangly's solution
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": "; _setupvar(#__VA_ARGS__); _debug(__VA_ARGS__);
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _debug() {cerr << '\n';}
vector<string> VARS;int VAR_IDX = 0;
void _setupvar(string v) {VARS = std::views::split(v, ',') | ranges::to<vector<string>>();VAR_IDX = 0;}

template<typename T, typename... Args>
void _debug(const T& first, const Args&... args) { cerr << VARS[VAR_IDX++] << ": "; _print(first); cerr << ", "; _debug(args...);}
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

    ll t, x, y, k;
    cin >> t;

    ll T = t;
    while(t--)
    {
        cin >> x >> y >> k;

        while(k)
        {
            if (x==1)
            {
                x = 1+k%(y-1); // when we reach 1 we'll start cycling
                break;
            }
            
            ll rem = x % y;
            ll inc = y - rem;
            inc = min(k, inc);
            k -= inc;
            x += inc;
            while (x % y == 0)
                x /= y;
        }

        cout << x << '\n';
    }
 
    return 0;
}

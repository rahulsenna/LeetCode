#include <bits/stdc++.h>
using namespace std;
#if 1
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
#define debug(...) cerr << __LINE__ << ": "; _debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

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
template<typename T, typename... Args>
void _debug(const T& first, const Args&... args) { cerr << " "; _print(first); cerr << " | "; _debug(args...);}
#endif 
int i =0;
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    ll N,X;
    cin >> N >> X;
    
    ll n;
    vector<ll> arr;
    while(cin >> n)
        arr.push_back(n);

    bool res = false;

    function<void (ll, ll)> rec = [&](ll idx, ll sum)
    {
        if (res)
            return;
        
        if (idx == N)
        {
            if (sum == X)
                res = true;
            return;
        }
        rec(idx+1, sum-arr[idx]);
        rec(idx+1, sum+arr[idx]);
    };
    
    rec(1,arr[0]);

    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
 
    return 0;
}

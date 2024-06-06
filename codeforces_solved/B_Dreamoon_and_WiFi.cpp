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
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
// #define debug(x) cerr << __LINE__ << ": " << #x <<" -> "; _print(x); cerr << '\n';
#define debug(...) cerr << __LINE__ << ": "; _debug(#__VA_ARGS__, __VA_ARGS__)
#else
// #define debug(x)
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

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    string s1, s2;
    cin >> s1 >> s2;
 
    int target = 0;

    for (auto &c: s1)
    {
        if (c=='+')
            target++;
        else
            target--;
    }
    int pos = 0;
    int steps = 0;
    
    for (auto &c: s2)
    {
        if (c=='+')
            pos++;
        else if (c=='-')
            pos--;
        else
            steps++;
    }

    if (steps==0)
    {
        if (pos==target)
            cout << fixed << setprecision(12) << 1.0;
        else
            cout << fixed << setprecision(12) << 0.0;
        return 0;
    }
    int success=0, fail=0;
    function<void (int, int)> rec = [&] (int steps_remain, int end)
    {
        if (steps_remain==0)
        {
            if (end == target)
                success++;
            else
                fail++;
            return;
        }
        rec(steps_remain-1, end+1);
        rec(steps_remain-1, end-1);
    };
    
    rec(steps,pos);
    double res = (double)(success)/(double)(success+fail);
    cout << fixed << setprecision(12) << res;



    return 0;
}

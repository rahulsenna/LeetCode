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

#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": "; _setupvar(#__VA_ARGS__); _debug(__VA_ARGS__);
void _print(s64 t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(r64 t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(u64 t) {cerr << t;}

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

set<vector<s64>> findTriplets(s64 number) {
    set<vector<s64>> uniqueTriplets;
    for (s64 i = 1; i <= cbrt(number); ++i) {
        if (number % i != 0) continue;
        for (s64 j = i; j <= sqrt(number / i); ++j) {
            if ((number / i) % j != 0) continue;
            s64 k = number / (i * j);
            if (i * j * k == number) {
                vector<s64> triplet = {i, j, k};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.emplace(triplet);
            }
        }
    }
    return uniqueTriplets;
}
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    s64 t, x, y, z, k;
    cin >> t;
    auto T = t;

    while(t--)
    {       
        cin >> x >> y >> z >> k;
        s64 cube_root = cbrt(k);
        if (cube_root * cube_root * cube_root == k && x == y && y == z)
            cout << (x - cube_root + 1) * (y - cube_root + 1) * (z - cube_root + 1) << '\n';
        else
        {
            auto trips = findTriplets(k);
            vector<s64> B_sides = {x,y,z};
            ranges::sort(B_sides);
            s64 res = 0;
            for (auto S_sides: trips)
            {
                s64 xx = B_sides[0]- S_sides[0]+1;
                s64 yy = B_sides[1]- S_sides[1]+1;
                s64 zz = B_sides[2]- S_sides[2]+1;

                if (!(xx > 0 && yy > 0 && zz > 0))
                    continue;
                
                res = max(res, xx*yy*zz);
            }
            cout << res << '\n';

        }
    }
 
    return 0;
}

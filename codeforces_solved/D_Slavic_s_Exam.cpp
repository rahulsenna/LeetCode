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

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

    s64 t;
    string s, T;
    cin >> t;

    while(t--)
    {
        cin >> s >> T;
        s64 done = 0;

        s64 idx = 0;
        for (auto &e: T)
        {
            while(idx < s.length())
            {
                auto &c = s[idx++];
                if (c == e)
                {
                    done++;
                    break;
                }
                    
                if (c == '?')
                {
                    done++;
                    c = e;
                    break;
                }
            }
        }
        
        while(idx < s.length())
        {
            if (s[idx]=='?')
                s[idx]='a';
            idx++;
        }
        if (done == T.length())
        {
            cout << "YES\n";
            cout << s << '\n';

        } else
        {
            cout << "NO\n"; 
        }

    }
 
    return 0;
}

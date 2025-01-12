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


int main()
{
    setup();

    s64 t,n,m;
    cin >> t;
    string N, M;
    while(t--)
    {
        cin >> n >> m >> N >> M;
        int res = 0;

        while(N.find(M) == -1)
        {
            N+=N;
            if(res++ > 5)
                break;
        }

        if ((N.find(M) == -1))
        { 
            cout << -1 << '\n';	
        } else
            cout << res << '\n';
    }
    return 0;
}
// https://codeforces.com/contest/1881/problem/A
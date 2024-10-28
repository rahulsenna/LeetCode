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

    s64 t, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if (k>n)
        {
            cout << "NO\n";
            continue;
        }

        if (n%k == 0)
        {
            cout << "YES\n";
            s64 kk = n/k;
            for (int i = 0; i < k; ++i)
                cout << kk << ' ';

            cout << '\n';
            continue;
        }
        s64 qoutient = n / k;
        s64 remainder = n%k;

        s64 QandR = qoutient+remainder;

        if ((QandR % 2 != 0 && qoutient % 2 != 0) or (QandR % 2 == 0 && qoutient % 2 == 0))
        {
            cout << "YES\n";
                 for (int i = 1; i < k; ++i)
                cout << qoutient << " ";
            cout << QandR << '\n';
            continue;
        }

        if (((k - 1) % 2 != 0) or qoutient == 1)
        {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        for (int i = 0; i < k/2; ++i)
            cout << qoutient-1 << " " << qoutient+1 << " ";
        cout << QandR << '\n'; 


    }
 
    return 0;
}

// https://codeforces.com/contest/1352/problem/B

#if  0 // my first approach (thought) but wasn't able to implement


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int n1 = n - (k - 1);
		if (n1 > 0 && n1 % 2 == 1) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "1 ";
			cout << n1 << endl;
			continue;
		}
		int n2 = n - 2 * (k - 1);
		if (n2 > 0 && n2 % 2 == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "2 ";
			cout << n2 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
#endif }  //0

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    int64_t _,n,a,b;    
    cin >> _;
    string s;
 
    while(cin >> n) {
 
        int64_t min_val = LLONG_MAX;
        cin >> a;
        for (int64_t  i = 0; i < n-1; ++i)
        {
        	 cin >> b;
             if (a>b)
             {
                min_val = 0;
                while(++i<n-1)
                    cin >> b;
                
                break;
             }
 
             min_val = min(min_val, ((b-a)+2)/2);
             a = b;
        }
        cout << min_val << '\n';
    }
 
    return 0;
}
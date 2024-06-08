#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long prev, curr;
        cin >> prev;
        long long res = LONG_MAX;
        for (long long j=0; j<n-1; ++j)
        {
            cin >> curr;
            res = min(res, max(curr,prev));
            prev = curr;
        }
        cout << res-1 << '\n';
    }
    
    return 0;
}
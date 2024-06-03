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

    function<void (int)> rec = [&](int n)
    {
        if (n == 1)
        {
            cout << 1;
            return;
        }
            
        cout << n << " ";
        rec(n-1);
    };

    int n; 
    while(cin >> n)
        rec(n);
 
    return 0;
}
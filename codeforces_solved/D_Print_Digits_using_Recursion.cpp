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

    function<void (int)> rec = [&] (int n)
    {
        if (n <= 0)
            return;

        rec(n/10);
        cout << n%10 << " ";
    };

    int n, _;
    cin >> _;

    while(cin >> n)
    {
        if (n == 0)
        {
            cout << "0 \n";
            continue;
        }
        rec(n);
        cout << '\n';
    } 
    return 0;
}
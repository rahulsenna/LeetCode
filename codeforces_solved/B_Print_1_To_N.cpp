#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    function<void (int)> rec = [&](int n)
	{
        if (n == 0 )
            return;       
        rec(n-1);
        cout << n << '\n';
    };
    int n;
    while(cin >> n)
        rec(n);
    
    return 0;
}

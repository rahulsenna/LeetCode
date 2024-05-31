#include <bits/stdc++.h>
using namespace std;

void rec(int n)
{
    if (n==0)
        return;
    cout << "I love Recursion\n";
    rec(n-1);
}
 
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;    
    

    while(cin >> n) {
        rec(n);
    }
 
    return 0;
}
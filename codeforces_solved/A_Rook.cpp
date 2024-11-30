#include <iostream>
using namespace std;
 
int main()
{
    int t;
    
    cin >> t;
    while (t--){
        char c;
        int x;
        
        cin >> c >> x;
        char a = 'a';
        for (int i=1; i<=8; i++){
            if (a==c) {
                a++;
                continue;
            }
            cout << a++ << x << ' ';
        }
        for (int i=1; i<=8; i++){
            if (i==x) {
            
                continue;
            }
            cout << c << i << ' ';
        }
        cout << '\n';
        
        
    }
 
    return 0;
}

// https://codeforces.com/contest/1907/problem/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n ,f, r;
    cin >> t;
    while(t--){
        cin >> n >> f >> r;
        std::vector<int> cubes;
        while(n--)
        {
            int c; cin >> c;
            cubes.push_back(c);
        }
        int fav = cubes[f-1];
        sort(cubes.begin(), cubes.end(), greater<int>());
        bool removed = find(cubes.begin(), cubes.begin()+r, fav) != cubes.begin()+r;
        bool kept = find(cubes.begin()+r, cubes.end(), fav) != cubes.end();
        
        if (removed && kept)
            cout << "MAYBE\n";
        else if (kept)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}

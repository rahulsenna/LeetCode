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

void part_one()
{
    std::vector<int> left;
    std::vector<int> right;

    int a,b;
    while (cin >> a >> b)
        left.emplace_back(a), right.emplace_back(b);
    
    ranges::sort(left);
    ranges::sort(right);

    int res = 0;
    for (int i = 0; i < 1000; ++i)
    	res += abs(left[i] - right[i]);
    
    std::cout << "res: " << res << '\n';
}
void part_two()
{
    std::vector<int> left_list;
    std::unordered_map<int, int> right_list_map;

    int a,b;
    while (cin >> a >> b)
    {
        left_list.emplace_back(a);
        right_list_map[b]++;
    }
    int res = 0;
    for (auto e: left_list)
    {
    	auto cnt = right_list_map[e];
    	res += e*cnt;
    }

    std::cout << "res: " << res << '\n';
}

int main()
{
    setup();
    // part_one();
    // part_two();
    return 0;
}

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
    string line;
    regex mul_pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int res = 0;
    while(getline(cin, line))
    {
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), mul_pattern);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) 
        {
            auto match = *i;
            res += stoi(match[1]) * stoi(match[2]);
        }
    }

    std::cout << "part_one res: " << res << '\n';
}

void part_two()
{    
    regex mul_pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    string line, bigline;
    while(getline(cin, line))
        bigline +=line;
    
    bigline = regex_replace(bigline, regex(R"(don't\(\).*?do\(\)|don't\(\).*)"), "");
    auto words_begin = std::sregex_iterator(bigline.begin(), bigline.end(), mul_pattern);
    auto words_end = std::sregex_iterator();
    u64 res = 0;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        auto match = *i;
        res += stoull(match[1]) * stoull(match[2]);
    }

    std::cout << "part_two res: " << res << '\n';
}
int main()
{
    setup();
    // part_one();
    part_two();
    return 0;
}



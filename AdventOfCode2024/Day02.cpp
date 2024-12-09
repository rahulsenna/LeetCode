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
    freopen("Day02.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
#include "debug_template.h"
#else
#define debug(...)
#endif


int issafe(vector<int> &report)
{
    bool increasing = report[0] < report[1];

    for (int i = 1; i < report.size(); ++i)
    {
        auto last = report[i-1];
        auto curr = report[i];
    	if (abs(last - curr) > 3)
            return i;
        if (last == curr)
            return i;
        if ((increasing and last > curr) )
            return i;
        
        if ((not increasing and last < curr))
            return i;
    }

    return -1;
}
void part_one()
{
    string line;
    int safe = 0;

    while(getline(cin, line))
    {
        std::istringstream iss(line);
        std::vector<int> report{istream_iterator<int>(iss), {}};
        if (issafe(report) == -1)
            safe++;
    }
    std::cout << "safe: " << safe << '\n';
}

void part_two()
{
    string line;
    int safe_count = 0;

    while(getline(cin, line))
    {
        std::istringstream iss(line);
        std::vector<int> report{istream_iterator<int>(iss), {}};
        int idx = -1;
        
        idx = issafe(report);
        if (idx == -1)
            safe_count++;
        else
        {
            bool safe = false;
            for (int i = -2; i < 2; ++i)
            {
                int n = idx + i;
                if (n < 0)
                    continue;
                vector<int> new_report = report;
                new_report.erase(new_report.begin() + n);

                if (issafe(new_report) == -1)
                {
                    safe = true;
                    break;
                }
            }
            if (safe)
                safe_count++;
        }
        
    }
    std::cout << "safe: " << safe_count << '\n';
}

int main()
{
    setup();
    // part_one();
    part_two();
}

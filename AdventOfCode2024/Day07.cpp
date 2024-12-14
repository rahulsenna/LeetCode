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

bool matched(vector<s64> &digits, s64 test_value)
{
    const int ops = digits.size() - 1;
    const int total_combinations = 1 << ops;
    for (int i = 0; i < total_combinations; ++i)
    {
        s64 test_sum = digits[0];
        std::bitset<32> bits(i);

        for (int j = 0; j < ops; ++j)
        {
            if (bits[j])
                test_sum *= digits[j + 1];
            else
                test_sum += digits[j + 1];
        }
        if (test_sum == test_value)
        {
            return true;
        }
    }
    return false;
}

void part_one()
{
    string line;
    s64 test_value = 0;
    char _;
    s64 res = 0;

    while (getline(cin, line))
    {
        stringstream ss(line);
        ss >> test_value >> _;
        vector<s64> digits{ istream_iterator<int>(ss),istream_iterator<int>() };

        if (matched(digits, test_value))
            res += test_value;
    }
    std::cout << "res: " << res << '\n';
}

void part_two()
{
    string line;
    s64 test_value = 0;
    char _;
    s64 res = 0;

    while (getline(cin, line))
    {
        stringstream ss(line);
        ss >> test_value >> _;
        vector<s64> digits{ istream_iterator<int>(ss),istream_iterator<int>() };
        if (matched(digits, test_value))
        {
            res += test_value;
            continue;
        }
            
        
        int ops_cnt = digits.size()-1;
        const int total_combinations = std::pow(3, ops_cnt);
        for (s64 i = 0; i < total_combinations; ++i)
        {
            s64 test_sum = digits[0];

            // Convert current number to trinary representation
            s64 temp_num = i;
            for (int j = 0; j < ops_cnt; ++j)
            {
                int curr_op = temp_num % 3;
                temp_num /= 3;
                
                if (curr_op == 2) // concat
                {
                    s64 sec = digits[j + 1];
                    s64 dig_cnt = 0;
                    while (sec) sec /= 10, dig_cnt++;

                    test_sum = test_sum * pow(10, dig_cnt) + digits[j + 1];
                    continue;
                }
                if (curr_op)
                    test_sum *= digits[j + 1];
                else
                    test_sum += digits[j + 1];
                
            }
            if (test_sum == test_value)
            {
                res += test_value;
                break;
            }
        }
    }

    std::cout << "res: " << res << '\n';

}
int main()
{
    setup();
    // part_one();
    part_two();
 
    return 0;
}

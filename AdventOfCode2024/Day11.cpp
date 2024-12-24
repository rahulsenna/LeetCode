#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
    fastio;
    freopen("Day11.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
}

void part_one()
{
    vector<u64> stones{ istream_iterator<u64>(cin), istream_iterator<u64>() };
    for (int _ = 0; _ < 25; ++_)
    {
        vector<u64> new_stones;
        for (u64 stone: stones)
        {
        	if (stone == 0)
                new_stones.push_back(1);

            else if (stone>9 and to_string(stone).length()%2==0)
            {
                string dig = to_string(stone);
                u64 left = stoull(dig.substr(0, dig.size()/2));
                u64 right = stoull(dig.substr(dig.size()/2, dig.size()/2));
                new_stones.push_back(left);
                new_stones.push_back(right);
            } else
            {
                new_stones.push_back(stone * 2024);
            }
        }
        stones = new_stones;
    }

    std::cout << "part_one: " << stones.size() << '\n';
}



void part_two()
{
    std::unordered_map<string, u64> memo;
    function< u64(u64, int)> count = [&](u64 stone, int blinks)
    {
        if (blinks == 0)
            return 1ull;
        if (memo.contains(to_string(stone)+"_"+to_string(blinks)))
            return memo[to_string(stone)+"_"+to_string(blinks)];
        
        u64 result = 0;
        if (stone == 0)
            result = count(1, blinks-1);
        else if (stone > 9 and to_string(stone).length() % 2 == 0)
        {
            string dig = to_string(stone);
            u64 left = stoull(dig.substr(0, dig.size() / 2));
            u64 right = stoull(dig.substr(dig.size() / 2, dig.size() / 2));
            result += count(left, blinks-1);
            result += count(right, blinks-1);
        }
        else
        {
            result += count(stone * 2024, blinks-1);
        }

        memo[to_string(stone)+"_"+to_string(blinks)] = result;
        return result;
    };

    u64 res = 0;
    vector<u64> stones{ istream_iterator<u64>(cin), istream_iterator<u64>() };
    for (u64 stone: stones)
    {   
        res += count(stone, 75);
    }

    std::cout << "part_two: " << res << '\n';
}

int main()
{
    setup();
    // part_one();
    part_two();
    return 0;
}

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
    freopen("Day09.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
#endif
}

#ifndef ONLINE_JUDGE
// #include "debug_template.h"
#else
#define debug(...)
#endif

void part_one() 
{

    string s;
    cin >> s;

    s64 size = 0;
    std::vector<int> block_digits;
    for (auto c: s)
    {
        int i = (c-'0');
        block_digits.emplace_back(i);
        size += i;
    }

    std::vector<int> blocks(size, -1);
    std::vector<int> emtpy_idxs;
    int idx = 0, dig =0;

    for (int i = 0; i < block_digits.size(); i += 2)
    {
        int a = block_digits[i];
        int b = block_digits[i + 1];

        for (int j = 0; j < a; ++j)
        {
            blocks[idx++] = dig;
        }

        for (int j = 0; j < b; ++j)
        {
            emtpy_idxs.push_back(idx++);
        }

        dig++;
    }

    int r_idx = size-1;

    for (auto e: emtpy_idxs)
    {
        if (e >= r_idx)
            break;
        while(blocks[r_idx] == -1)
            r_idx--;
        
        swap(blocks[e], blocks[r_idx]);
        r_idx--;
    }
    s64 res = 0;
    for (int i = 0; i < blocks.size(); ++i)
    {
        if (blocks[i] == -1)  break;
        res += i*blocks[i];

    }
    std::cout << "res: " << res << '\n'; // 6435922584968; 

}

void part_two()
{
    string s;
    cin >> s;

    s64 size = 0;
    std::vector<int> block_digits;
    for (auto c : s)
    {
        int i = (c - '0');
        block_digits.emplace_back(i);
        size += i;
    }

    std::vector<int> blocks(size, 0);
    std::vector<pair<int,int>> emtpy_blocks;
    std::vector<pair<int,int>> filled_blocks;
    int idx = 0, dig =0;

    for (int i = 0; i < block_digits.size(); i += 2)
    {
        int a = block_digits[i];
        int b = block_digits[i + 1];
        filled_blocks.push_back({idx,a});
        emtpy_blocks.push_back({idx+a,b});
        for (int j = 0; j < a; ++j)
        {
            blocks[idx++] = dig;
        }
        idx += b;

        dig++;
    }

    reverse(filled_blocks.begin(), filled_blocks.end());

    for (auto [f_idx, f_blocks]: filled_blocks)
    {
        for (auto &[e_idx, e_blocks]: emtpy_blocks)
        {
            if (e_idx >= f_idx)
                break;

            if (e_blocks >= f_blocks)
            {
                for (int x = e_idx; x < e_idx+f_blocks; ++x)
                {
                	 blocks[x] = blocks[f_idx];
                }
                for (int x = 0; x < f_blocks; ++x)
                {
                	 blocks[f_idx++] = 0;
                }

                e_blocks -= f_blocks;
                e_idx += f_blocks;

                break;
            }
        }
    }
    s64 res = 0;
    for (int i = 0; i < blocks.size(); ++i)
    {
    	 res += i*blocks[i];
    }

    std::cout << "res2: " << res << '\n';
   
}

int main()
{
    setup();
    // part_one();
    part_two();
    return 0;
}

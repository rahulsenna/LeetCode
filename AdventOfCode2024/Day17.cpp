#include <bits/stdc++.h>
using namespace std;

typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;


vector<s64> 
run_program(const vector<s64>& program, s64 a=0, s64 b=0, s64 c=0)
{
    s64 PC = 0;
    s64 N= program.size();
    s64 combo[8] {0,1,2,3,a,b,c,7};
    s64& A = combo[4], & B = combo[5], & C = combo[6];
    std::vector<s64> out;
    while(PC<N)
    {
        switch(program[PC])
        {
            case 0: 
            {
                A = A / (1 << combo[program[PC + 1]]);
                PC+=2;
                break;
            };
            case 1:
            {
                B = B^program[PC+1];
                PC+=2;
                break;
            };
            case 2:
            {
                B = combo[program[PC+1]]%8;
                PC+=2;
                break;
            }
            case 3:
            {
                if (A==0)
                {
                    PC+=2;
                    break;
                }
                PC = program[PC+1];
                break;
            }
            case 4:
            {
                B = B^C;
                PC+=2;
                break;
            }
            case 5:
            {
                // cout << combo[program[PC+1]]%8 << ',';
                out.push_back(combo[program[PC+1]]%8);
                PC+=2;
                break;
            }
            case 6:
            {
                B = A / (1 << combo[program[PC + 1]]);
                PC+=2;
                break;
            }
            case 7:
            {
                C = A / (1 << combo[program[PC + 1]]);
                PC+=2;
                break;
            }
        }
    }
    return out;
}

void
part_one(vector<s64>& program, s64 a, s64 b, s64 c)
{
    auto res = run_program(program, a, b, c);
    for (auto e: res)
    	cout << e << ',';
}


bool reverse_eng(s64 p, s64 r, const vector<s64>& program)
{
    if (p < 0) 
    {
        std::cout << "part_two: " << r << std::endl;
        return true;
    }

    for (s64 d = 0; d < 8; d++) {
        s64 a = (r << 3) | d;
        s64 i = 0, b = 0, c = 0, w = 0;
        while (i < program.size())
        {
            s64 o;
            if (program[i + 1] <= 3) 
                o = program[i + 1];
            else if (program[i + 1] == 4) 
                o = a;
            else if (program[i + 1] == 5) 
                o = b;
            else if (program[i + 1] == 6) 
                o = c;

            switch (program[i])
            {
                case 0:a >>= o;break;
                case 1:b ^= program[i + 1];break;
                case 2:b = o & 7;break;
                case 3:if (a != 0) { i = program[i + 1] - 2; }break;
                case 4:b ^= c;break;
                case 5:w = o & 7;goto breakWhile;
                case 6:b = a >> o;break;
                case 7:c = a >> o;break;
            }
            i += 2;
        }
        breakWhile:

        if (w == program[p] && reverse_eng(p - 1, (r << 3) | d, program)) {
            return true;
        }
    }
    return false;
}

void match_last_few_bits(vector<s64> program)
{
    auto not_equal = [](const vector<s64>& a, const vector<s64>& b, int size) -> bool
    {
        int cnt =  a.size() - size;
        if (b.size() < cnt)
            return true;
        return not equal(a.rbegin(), a.rbegin()+cnt, b.rbegin());
    };

    s64 A = 0;
    for (int i = program.size() - 1; i >= 0; --i)
    {
        A = A << 3;
        while (not_equal(program, run_program(program, A), i))
            A += 1;   
    }

    cout << "part_two: " << A << '\n';
}
void part_two(vector<s64> program)
{
    // match_last_few_bits(program);
    reverse_eng(program.size() - 1, 0, program);
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    s64 a,b,c;
    string _;
    cin >> _ >> _ >> a >> _ >> _ >> b >> _ >> _ >> c >> _;
    vector<s64> program;
    s64 i;
    char __;
    while(cin >> i)
    {
        program.push_back(i);
        cin >> __;
    }
    
    // part_one(program, a,b,c);
    part_two(program);


	return(0);
}

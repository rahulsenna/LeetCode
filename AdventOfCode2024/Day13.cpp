#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef int64_t s64;
typedef uint64_t u64;
typedef long double r64;

inline void setup() {
    fastio;
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout), freopen("error.txt", "w", stderr);
}

void part_one()
{
    string line, _;
    char c;

    auto proc = [&]
    {
        int ax, ay, bx, by, X, Y;

        stringstream ss(line);        
        ss >> _ >> _ >> c >> ax >> c >> c >> ay;
        getline(cin, line);
        ss = stringstream(line);
        ss >> _ >> _ >> c >> bx >> c >> c >> by;

        getline(cin, line);
        ss = stringstream(line);
        ss >> _ >> c >> c >> X >> c >> c >> c >> Y;
        getline(cin, line);
        

        int div_x = X/bx, div_y = Y/by;

        if (div_x == div_y and X % bx == 0 and Y % by == 0)
        {
            return div_x;
        }
        int div_b = min(div_x, div_y);

        while(div_b>0)
        {
            int cx = bx * div_b, cy = by * div_b;
            int rx = X-cx, ry = Y-cy;

            if ((rx % ax == 0) and (ry % ay == 0))
            { 
                int div_a = rx / ax;
                if ((div_a * ax + cx) == X and (div_a * ay + cy) == Y)
                    return (div_a * 3 + div_b);
            }
            div_b--;
        }
        return 0;
    };
    int res = 0;
    while(getline(cin, line))
    {
        res += proc();
    }
    std::cout << "res: " << res << '\n';    
}

void part_two()
{
    
    string line, _;
    char c;

    auto proc = [&]
    {
        s64 ax, ay, bx, by, X, Y;

        stringstream ss(line);        
        ss >> _ >> _ >> c >> ax >> c >> c >> ay;
        getline(cin, line);
        ss = stringstream(line);
        ss >> _ >> _ >> c >> bx >> c >> c >> by;

        getline(cin, line);
        ss = stringstream(line);
        ss >> _ >> c >> c >> X >> c >> c >> c >> Y;
        getline(cin, line);
        
        X += 10000000000000, Y += 10000000000000;

        // i*ax + j*bx = X;
        // i*ay + j*by = Y;

        // i = (X-j*bx) / ax
        // i*ay + j*by = Y; // subtitue i with (X-j*bx) / ax
        // ay *(X-j*bx) /ax + j*by = Y
        // X*ay - j*bx*ay + j*by*ax = Y*ax
        // X*ay + j*by*ax - j*bx*ay  = Y*ax
        // j*by*ax - j*bx*ay  = Y*ax - X*ay;
        // j (by*ax - bx*ay) = Y*ax - X*ay
        
        // j = (Y*ax - X*ay) / (by*ax - bx*ay)
        // i = (X-j*bx) / ax

        s64 j = (Y*ax - X*ay) / (by*ax - bx*ay);
        s64 i = (X-j*bx) / ax;

        if (i*ax + j*bx == X and i*ay + j*by == Y)
            return (i*3+j);
            
        
        return (0LL);
    };
    s64 res = 0;
    while(getline(cin, line))
    {
        res += proc();
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

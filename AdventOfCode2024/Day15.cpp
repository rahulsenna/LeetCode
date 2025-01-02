#include <bits/stdc++.h>
using namespace std;

void part_one()
{
    string line;
    vector<string> grid;
    pair<int, int> robot;
    int Y = 0;
    while (getline(cin, line) and line != "")
    {
        int x = line.find('@');
        if (x != -1)
        {
            line[x] = '.';
            robot = { x,Y };
        }
        grid.push_back(line);
        Y++;
    };
    vector<int> moves;
    pair<int, int> DIR[4] = { {0,-1},{0,1},{-1,0},{1,0} };

    while (getline(cin, line))
    {
        for (auto c : line)
        {
            if (c == '^')
                moves.push_back(0);
            else if (c == 'v')
                moves.push_back(1);
            else if (c == '<')
                moves.push_back(2);
            else if (c == '>')
                moves.push_back(3);
        }
    }
    auto [rx, ry] = robot;
    for (auto move : moves)
    {
        auto [dx, dy] = DIR[move];
        int nrx = rx + dx, nry = ry + dy;
        if (grid[nry][nrx] == '.')
        {
            rx += dx, ry += dy;
            continue;
        }

        if (grid[nry][nrx] == 'O')
        {
            while (1)
            {
                nry += dy, nrx += dx;
                if (grid[nry][nrx] == '#')
                    break;
                if (grid[nry][nrx] == '.')
                {
                    grid[nry][nrx] = 'O';
                    rx += dx, ry += dy;
                    grid[ry][rx] = '.';
                    break;
                }
            }
        }
    }
    for (auto s : grid)
        cout << s << '\n';

    int N = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0;i < N;++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 'O')
                res += 100 * i + j;
        }
    }
    cout << res << '\n';
}


void part_two()
{
    string line;
    vector<string> grid;
    pair<int, int> robot;
    int Y = 0;
    while (getline(cin, line) and line != "")
    {
        string l;
        for (char c : line)
        {
            if (c == '@')
            {
                robot = { l.size(),Y };
                l += "..";
                continue;
            }
            if (c == 'O')
            {
                l += "[]";
                continue;
            }
            l += c;
            l += c;
        }
        grid.push_back(l);
        Y++;
    };
    vector<int> moves;
    pair<int, int> DIR[4] = { {0,-1},{0,1},{-1,0},{1,0} };

    while (getline(cin, line))
    {
        for (auto c : line)
        {
            if (c == '^')
                moves.push_back(0);
            else if (c == 'v')
                moves.push_back(1);
            else if (c == '<')
                moves.push_back(2);
            else if (c == '>')
                moves.push_back(3);
        }
    }
    auto [rx, ry] = robot;

    for (auto move : moves)
    {
        auto [dx, dy] = DIR[move];
        int nrx = rx + dx, nry = ry + dy;
        if (grid[nry][nrx] == '.')
        {
            rx += dx, ry += dy;
            continue;
        }
        if (grid[nry][nrx] == '#')
            continue;

        if (move > 1)
        {
            while (1)
            {
                nry += dy, nrx += dx;
                if (grid[nry][nrx] == '#')
                    break;
                if (grid[nry][nrx] == '.')
                {
                    if (move == 2)
                    {
                        int to = rx + dx * 2;
                        while (nrx < to)
                        {
                            grid[ry][nrx++] = '[';
                            grid[ry][nrx++] = ']';
                        }
                    }
                    else if (move == 3)
                    {
                        int to = rx + dx * 2;
                        while (nrx > to)
                        {
                            grid[ry][nrx--] = ']';
                            grid[ry][nrx--] = '[';
                        }
                    }
                    rx += dx, ry += dy;
                    grid[ry][rx] = '.';
                    break;
                }
            }
        }
        else
        {
            vector<pair<int, int>> boxes;
            if (grid[nry][nrx] == '[')
            {
                boxes.push_back({ nry, nrx });
            }
            else if (grid[nry][nrx] == ']')
            {
                boxes.push_back({ nry, nrx - 1 });
            }
            bool blocks = false;
            for (int i = 0; i < boxes.size(); ++i)
            {

                auto [y, x] = boxes[i];

                if (grid[y + dy][x] == '#' or grid[y + dy][x + 1] == '#')
                {
                    blocks = true;
                    break;
                }
                if (grid[y + dy][x] == '[') // exactly over
                {
                    boxes.push_back({ y + dy,x });
                    continue;
                }
                if (grid[y + dy][x] == ']') // over to the left
                {
                    boxes.push_back({ y + dy,x - 1 });
                }
                if (grid[y + dy][x + 1] == '[') // over to the right
                {
                    boxes.push_back({ y + dy,x + 1 });
                }
            }

            if (blocks)
                continue;

            for (auto [y, x] : boxes)
            {
                grid[y][x] = '.';
                grid[y][x + 1] = '.';
            }

            for (auto [y, x] : boxes)
            {
                grid[y + dy][x] = '[';
                grid[y + dy][x + 1] = ']';
            }
            rx += dx, ry += dy;
        }
    }

    for (auto s : grid)
        cout << s << '\n';

    int N = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0;i < N;++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '[')
                res += 100 * i + j;
        }
    }
    cout << res << '\n';

}
int main()
{
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

    // part_one();
    part_two();
    return(0);
}

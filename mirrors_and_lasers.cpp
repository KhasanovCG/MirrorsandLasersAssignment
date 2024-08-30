#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
    Point(int a, int b) : x(a), y(b) {}

    bool operator<(const Point &other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
};

int r, c, m, n;
map<int, map<int, char>> mirrors;

bool traceLaser(int startX, int startY, int startDir, vector<Point> &path, set<Point> &mirror_positions)
{
    int x = startX, y = startY;
    int dir = startDir;
    set<Point> visited;

    while (true)
    {
        // moove in the current direction
        if (dir == 0)
            y++; // right
        else if (dir == 1)
            x++; // down
        else if (dir == 2)
            y--; // left
        else if (dir == 3)
            x--; // up

        // check ifs out of bounds
        if (x < 1 || x > r || y < 1 || y > c)
        {
            if (x == r && y == c + 1)
            {
                return true; // reached the detector
            }
            return false;
        }

        Point current(x, y);
        if (visited.count(current))
        {
            return false; // detected a loop
        }

        visited.insert(current);
        path.push_back(current);

        // change direction if theres a mirror
        if (mirrors.count(x) && mirrors[x].count(y))
        {
            if (mirrors[x][y] == '/')
            {
                if (dir == 0)
                    dir = 3; // right -> up
                else if (dir == 1)
                    dir = 2; // down -> left
                else if (dir == 2)
                    dir = 1; // left -> down
                else if (dir == 3)
                    dir = 0; // up -> right
            }
            else if (mirrors[x][y] == '\\')
            {
                if (dir == 0)
                    dir = 1; // right -> down
                else if (dir == 1)
                    dir = 0; // down -> right
                else if (dir == 2)
                    dir = 3; // left -> up
                else if (dir == 3)
                    dir = 2; // up -> left
            }
        }
        else
        {
            mirror_positions.insert(current);
        }
    }
}

int main()
{
    cin >> r >> c >> m >> n;

    for (int i = 0; i < m; i++)
    {
        int ri, ci;
        cin >> ri >> ci;
        mirrors[ri][ci] = '/';
    }

    for (int i = 0; i < n; i++)
    {
        int ri, ci;
        cin >> ri >> ci;
        mirrors[ri][ci] = '\\';
    }

    vector<Point> forwardPath;
    set<Point> forwardMirrorPositions;
    bool forwardSuccess = traceLaser(1, 1, 0, forwardPath, forwardMirrorPositions);

    if (forwardSuccess)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<Point> backwardPath;
    set<Point> backwardMirrorPositions;
    bool backwardSuccess = traceLaser(r, c, 2, backwardPath, backwardMirrorPositions);

    if (backwardSuccess)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<Point> validPositions;

    for (const auto &pos : forwardMirrorPositions)
    {
        if (backwardMirrorPositions.count(pos))
        {
            validPositions.push_back(pos);
        }
    }

    sort(validPositions.begin(), validPositions.end());

    if (!validPositions.empty())
    {
        cout << validPositions.size() << " " << validPositions[0].x << " " << validPositions[0].y << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}

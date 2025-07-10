#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {-1, 0, 1, 0}; // N, E, S, W
int dy[] = {0, 1, 0, -1};
char dirChar[] = {'N', 'E', 'S', 'W'};

int get_start_dir(int sx, int sy, int n) {
    if (sx == 1 && sy == 1) return 1;        // Top-left → East
    if (sx == 1 && sy == n) return 2;        // Top-right → South
    if (sx == n && sy == n) return 3;        // Bottom-right → West
    if (sx == n && sy == 1) return 0;        // Bottom-left → North
    return -1;
}

bool in_bounds(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve_case(int tc) {
    int n;
    cin >> n;
    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--; // 0-based indexing

    int dir = get_start_dir(sx + 1, sy + 1, n);
    int x = sx, y = sy;

    int steps = 0;
    string path;

    // Set to keep visited states (x, y, dir) to avoid loops
    set<tuple<int, int, int>> visited;

    while (steps <= 10000) {
        if (x == ex && y == ey) {
            cout << "Case #" << tc << ": " << steps << "\n" << path << "\n";
            return;
        }

        if (visited.count({x, y, dir})) {
            cout << "Case #" << tc << ": Edison ran out of energy.\n";
            return;
        }

        visited.insert({x, y, dir});

        // Try left, straight, right, back
        bool moved = false;
        for (int turn = 3; turn <= 6; turn++) {
            int ndir = (dir + turn) % 4;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (in_bounds(nx, ny, n) && maze[nx][ny] == '.') {
                x = nx;
                y = ny;
                dir = ndir;
                path.push_back(dirChar[dir]);
                steps++;
                moved = true;
                break;
            }
        }

        if (!moved) {
            cout << "Case #" << tc << ": Edison ran out of energy.\n";
            return;
        }
    }

    cout << "Case #" << tc << ": Edison ran out of energy.\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        solve_case(tc);
    }

    return 0;
}

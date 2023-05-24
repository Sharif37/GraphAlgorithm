#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
bool labyrinth[N][N], visited[N][N], monsters[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int sx, sy, ex, ey;

// Function to check if the current coordinate is valid
bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (labyrinth[x][y] || visited[x][y]) return false;
    return true;
}

// Function to check if the current coordinate is on the boundary
bool isBoundary(int x, int y) {
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) return true;
    return false;
}

// Function to simulate the movements of the monsters
void moveMonsters() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (monsters[i][j]) q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny)) {
                monsters[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

// Function to check if it is possible to reach the boundary
bool bfs() {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (isBoundary(x, y)) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny) && !monsters[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        moveMonsters();
    }

    return false;
}

int main() {
    cin >> n >> m;

    // Input the labyrinth
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') labyrinth[i][j] = true;
            else if (c == 'A') sx = i, sy = j;
            else if (c == 'M') monsters[i][j] = true;

        }
    }

    if (bfs()) {
        vector<pair<int, int>> path;
        vector<string> directions;
        int x = ex, y = ey;

        while (x != sx || y != sy) {
            path.push_back({x, y});
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (visited[nx][ny]) {
                    x = nx, y = ny;
                    if (i == 0) directions.push_back("U");
                    else if (i == 1) directions.push_back("R");
                    else if (i == 2) directions.push_back("D");
                    else if (i == 3) directions.push_back("L");
                    break;
                }
            }
        }

        path.push_back({sx, sy});
        reverse(path.begin(), path.end());
        reverse(directions.begin(), directions.end());

        cout << "YES" << endl;
        for (auto [x, y] : path) cout << x + 1 << " " << y + 1 << endl;
        for (auto dir : directions) cout << dir << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

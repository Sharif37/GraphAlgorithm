#include<bits/stdc++.h>
using namespace std ;
vector<vector<char>> map;
vector<vector<bool>> visited;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
    int n, m, room_count = 0;
    cin >> n >> m;
   // map.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.' && !visited[i][j]) {
                room_count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (is_valid(nx, ny, n, m) && map[nx][ny] == '.' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << room_count << endl;
    return 0;
}

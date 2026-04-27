// 1391. Check if There is a Valid Path in a Grid
// Daily Challenge - 27/04/2026

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<vector<vector<int>>> dir = {
            {},
            {{0,-1},{0,1}},        // 1
            {{-1,0},{1,0}},        // 2
            {{0,-1},{1,0}},        // 3
            {{0,1},{1,0}},         // 4
            {{0,-1},{-1,0}},       // 5
            {{0,1},{-1,0}}         // 6
        };

        auto isValid = [&](int x, int y, int px, int py) {
            for (auto &d : dir[grid[x][y]]) {
                if (x + d[0] == px && y + d[1] == py) {
                    return true;
                }
            }
            return false;
        };

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (auto &d : dir[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (vis[nx][ny]) continue;

                if (isValid(nx, ny, x, y)) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};
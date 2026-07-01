class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &[dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        auto canReach = [&](int safe) {
            if (dist[0][0] < safe) return false;

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            queue<pair<int, int>> qq;
            qq.push({0, 0});
            vis[0][0] = true;

            while (!qq.empty()) {
                auto [x, y] = qq.front();
                qq.pop();

                if (x == n - 1 && y == n - 1)
                    return true;

                for (auto &[dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        !vis[nx][ny] && dist[nx][ny] >= safe) {
                        vis[nx][ny] = true;
                        qq.push({nx, ny});
                    }
                }
            }

            return false;
        };

        int low = 0, high = 2 * n, ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canReach(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
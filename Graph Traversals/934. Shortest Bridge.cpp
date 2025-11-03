class Solution {
private:
    int n;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int, int>>& q) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) {
            return;
        }
        grid[r][c] = 2; 
        q.push({r, c});

        for (auto& dir : directions) {
            dfs(grid, r + dir[0], c + dir[1], q);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int, int>> q;
        bool found_island = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found_island = true;
                    break;
                }
            }
            if (found_island) break;
        }
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            return distance; 
                        }
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            distance++;
        }
        return -1;
    }
};

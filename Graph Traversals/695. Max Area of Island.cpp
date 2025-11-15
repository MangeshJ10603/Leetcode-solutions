class Solution {
private:
    int R, C;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0; 
        
        return 1 + dfs(grid, r + 1, c) + 
                   dfs(grid, r - 1, c) + 
                   dfs(grid, r, c + 1) + 
                   dfs(grid, r, c - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        R = grid.size();
        C = grid[0].size();
        int max_area = 0;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 1) {
                    max_area = max(max_area, dfs(grid, r, c));
                }
            }
        }
        return max_area;
    }
};

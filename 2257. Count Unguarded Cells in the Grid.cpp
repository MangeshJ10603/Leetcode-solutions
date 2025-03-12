class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        for (int j = col + 1; j < n; j++) {
            if (grid[row][j] == 2 || grid[row][j] == 3) break;
            grid[row][j] = 1;
        }
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 2 || grid[row][j] == 3) break;
            grid[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (auto& it : guards) {
            grid[it[0]][it[1]] = 2;
        }
        for (auto& it : walls) {
            grid[it[0]][it[1]] = 3;
        }
        for (auto& it : guards) {
            solve(it[0], it[1], grid);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

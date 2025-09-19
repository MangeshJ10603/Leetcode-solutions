class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<char>>& board) {
        visited[i][j] = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int n = board.size();
        int m = board[0].size();
        for (int k = 0; k < 4; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (ii >= 0 && jj >= 0 && ii < n && jj < m && !visited[ii][jj] &&
                board[ii][jj] == 'O') {
                visited[ii][jj] = 1;
                dfs(ii, jj, visited, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,false));
        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && board[0][j] == 'O') {
                dfs(0, j, visited, board);
            }
            if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, visited, board);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(i, 0, visited, board);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, visited, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    visited[i][j] = 1;
                    board[i][j] = 'X';
                }
            }
        }
    }
};

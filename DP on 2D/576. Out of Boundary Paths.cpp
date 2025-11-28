class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[startRow][startColumn] = 1;
        
        long long totalPaths = 0;
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int move = 1; move <= maxMove; ++move) {
            vector<vector<long long>> next_dp(m, vector<long long>(n, 0));
            
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (dp[r][c] > 0) {
                        for (auto& dir : directions) {
                            int nr = r + dir[0];
                            int nc = c + dir[1];

                            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                                totalPaths = (totalPaths + dp[r][c]) % MOD;
                            } else {
                                next_dp[nr][nc] = (next_dp[nr][nc] + dp[r][c]) % MOD;
                            }
                        }
                    }
                }
            }
            dp = next_dp;
        }

        return (int)totalPaths;
    }
};

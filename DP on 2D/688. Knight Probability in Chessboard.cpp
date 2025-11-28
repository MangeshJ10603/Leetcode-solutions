class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) return 1.0;
        
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        dp[row][column] = 1.0;
        
        int directions[8][2] = {
            {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
            {2, -1}, {2, 1}, {1, -2}, {1, 2}
        };

        for (int move = 1; move <= k; ++move) {
            vector<vector<double>> next_dp(n, vector<double>(n, 0.0));
            
            for (int curr_r = 0; curr_r < n; ++curr_r) {
                for (int curr_c = 0; curr_c < n; ++curr_c) {
                    if (dp[curr_r][curr_c] > 0) {
                        for (auto& dir : directions) {
                            int next_r = curr_r + dir[0];
                            int next_c = curr_c + dir[1];

                            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
                                next_dp[next_r][next_c] += dp[curr_r][curr_c] * 0.125;
                            }
                        }
                    }
                }
            }
            dp = next_dp;
        }

        double totalProb = 0.0;
        for (int i = 0; i < n; ++i) {
            totalProb = accumulate(dp[i].begin(), dp[i].end(), totalProb);
        }

        return totalProb;
    }
};

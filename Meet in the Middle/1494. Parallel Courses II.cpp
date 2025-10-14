class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n, 0);
        for (auto &r : relations)
            pre[r[1] - 1] |= 1 << (r[0] - 1);

        int total = 1 << n;
        vector<int> dp(total, n + 1);
        dp[0] = 0;

        for (int mask = 0; mask < total; mask++) {
            int available = 0;
            for (int i = 0; i < n; i++)
                if ((mask & pre[i]) == pre[i]) available |= 1 << i;

            available &= ~mask; 

            for (int sub = available; sub; sub = (sub - 1) & available)
                if (__builtin_popcount(sub) <= k)
                    dp[mask | sub] = min(dp[mask | sub], dp[mask] + 1);
        }

        return dp[total - 1];
    }
};

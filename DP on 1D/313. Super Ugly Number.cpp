class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> dp(n);
        vector<int> pointers(k, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            long long min_val = LLONG_MAX;
            for (int j = 0; j < k; ++j) {
                min_val = min(min_val, dp[pointers[j]] * primes[j]);
            }
            dp[i] = min_val;
            for (int j = 0; j < k; ++j) {
                if (min_val == dp[pointers[j]] * primes[j]) {
                    pointers[j]++;
                }
            }
        }
        return (int)dp[n - 1];
    }
};

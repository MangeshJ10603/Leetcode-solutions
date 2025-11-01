class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev_idx(n, -1);
        int last_index = 0;
        int maxl = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                    if (dp[i] > maxl) {
                        maxl = dp[i];
                        last_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while (last_index >= 0) {
            result.push_back(nums[last_index]);
            last_index = prev_idx[last_index];
        }
        return result;
    }
};

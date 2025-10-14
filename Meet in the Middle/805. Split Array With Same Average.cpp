class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (n == 1) return false;

        for (int &x : nums) {
            x = x * n - total;
        }

        int mid = n / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        unordered_set<int> leftSums;
        int leftSize = left.size();
        for (int mask = 1; mask < (1 << leftSize); mask++) {
            int sum = 0;
            for (int i = 0; i < leftSize; i++) {
                if (mask & (1 << i)) sum += left[i];
            }
            if (sum == 0) return true;
            leftSums.insert(sum);
        }

        int rightSize = right.size();
        int totalRightSum = accumulate(right.begin(), right.end(), 0);
        for (int mask = 1; mask < (1 << rightSize); mask++) {
            int sum = 0;
            for (int i = 0; i < rightSize; i++) {
                if (mask & (1 << i)) sum += right[i];
            }
            if (sum == 0) return true;
            if (sum != totalRightSum && leftSums.count(-sum)) return true;
        }

        return false;
    }
};

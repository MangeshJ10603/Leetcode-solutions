
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSoFar = nums[0];
        int currentMax = 0;
        int minSoFar = nums[0];
        int currentMin = 0;

        for (int n : nums) {
            totalSum += n;
            currentMax = max(n, currentMax + n);
            maxSoFar = max(maxSoFar, currentMax);
            currentMin = min(n, currentMin + n);
            minSoFar = min(minSoFar, currentMin);
        }

        if (maxSoFar < 0) {
            return maxSoFar;
        }

        return max(maxSoFar, totalSum - minSoFar);
    }
};

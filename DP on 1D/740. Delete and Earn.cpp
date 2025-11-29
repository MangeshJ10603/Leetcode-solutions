
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        map<int, int> pointsMap;
        int maxVal = 0;
        
        for (int num : nums) {
            pointsMap[num] += num;
            maxVal = max(maxVal, num);
        }
        
        vector<int> dp(maxVal + 1, 0);
        
        dp[1] = pointsMap[1];

        for (int i = 2; i <= maxVal; ++i) {
            int currentPoints = pointsMap[i];
            
            int take = dp[i - 2] + currentPoints;
            int leave = dp[i - 1];
            
            dp[i] = max(take, leave);
        }
        
        return dp[maxVal];
    }
};

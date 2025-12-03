class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = n - 1;
                long long required_sum = (long long)target - nums[i] - nums[j];
                while (left < right) {
                    int current_sum = nums[left] + nums[right];
                    if (current_sum == required_sum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;                     
                        left++;
                        right--;
                    } else if (current_sum < required_sum) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

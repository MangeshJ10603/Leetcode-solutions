class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxidiff=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
            int diff=abs(nums[i]-nums[i-1]);
            maxidiff = max(maxidiff, diff);
        }
        int diff = abs(nums[nums.size()-1]-nums[0]);
        maxidiff=max(maxidiff,diff);
        return maxidiff;
    }
};

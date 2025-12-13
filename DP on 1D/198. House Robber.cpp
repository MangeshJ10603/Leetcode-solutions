class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int rob_prev2=0;
        int rob_prev1=0;
        int curr_max=0;
        for(int num:nums){
            curr_max=max(rob_prev1,rob_prev2+num);
            rob_prev2=rob_prev1;
            rob_prev1=curr_max;
        }
        return curr_max;
    }
};

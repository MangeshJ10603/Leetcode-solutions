class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int prev2=0;
        int prev1=0;
        int curr_max=0;
        for(int i=start;i<=end;i++){
            curr_max=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr_max;
        }
        return curr_max;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int range1=solve(nums,0,n-2);
        int range2=solve(nums,1,n-1);
        return max(range1,range2);
    }
};

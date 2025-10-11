class Solution {
public:
    vector<int> solve(vector<int>& nums){
        int n=nums.size();
        vector<int> result;
        for(int mask=0;mask<(1<<n); mask++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) sum+=nums[i];
            }
            result.push_back(sum);
        }
        return result;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        vector<int> leftsum=solve(left);
        vector<int> rightsum=solve(right);
        sort(rightsum.begin(),rightsum.end());
        int ans=abs(goal);
        for(int s:leftsum){
            int target=goal-s;
            auto it=lower_bound(rightsum.begin(),rightsum.end(),target);
            if(it!=rightsum.end()){
                ans=min(ans,abs(s-goal+*it));
            }
            if(it!=rightsum.begin()){
                --it;
                ans=min(ans,abs(s-goal+*it));
            }
        }
        return ans;
    }
};

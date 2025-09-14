class Solution {
public:
    bool solve(vector<int>& nums,int mid, int k){
        int count=1;
        long long curr=0;
        for(int x:nums){
            if(curr+x>mid){
                count++;
                curr=x;
                if(count>k) return false;
            }else{
                curr+=x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left=*max_element(nums.begin(),nums.end());
        long long right=accumulate(nums.begin(),nums.end(),0LL);
        long long result=right;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(solve(nums,mid,k)){
                result=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return (int)result;
    }
};

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& currsubset,
               vector<vector<int>>& subsets) {
        if (i == nums.size()) {
            subsets.push_back(currsubset);
            return;
        }
        currsubset.push_back(nums[i]);
        solve(nums, i + 1, currsubset, subsets);
        currsubset.pop_back();
        solve(nums, i + 1, currsubset, subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currsubset;
        solve(nums, 0, currsubset, subsets);
        int result = 0;
        for (auto& curr : subsets) {
            int x = 0;
            for (int num : curr) {
                x ^= num;
            }
            result += x;
        }
        return result;
    }
};

//----------------------------------------------------------------

class Solution {
public: 
    int solve(vector<int>& nums, int i, int x){
        if(i==nums.size()){
            return x;
        }
        int include=solve(nums,i+1,nums[i]^x);
        int exclude=solve(nums,i+1,x);
        return include+exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};

//--------------------------------------------------------------------

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int& num:nums){
            result|=num;
        }
        return result<<(n-1);
    }
};

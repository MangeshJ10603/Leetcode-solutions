class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lambdaP = [](int num){
            return num>0;
        };
        auto lambdaN = [](int num){
            return num<0;
        };
        int countpositive = count_if(nums.begin(), nums.end(), lambdaP);
        int countnegative = count_if(nums.begin(),nums.end(), lambdaN);
        return max(countpositive, countnegative);
    }
};

//----------------------------------------------------------------------------


class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int firstPositive = lower_bound(nums.begin(),nums.end(),1)-nums.begin();
        int firstZero = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        return max(n-firstPositive,firstZero);
    }
};

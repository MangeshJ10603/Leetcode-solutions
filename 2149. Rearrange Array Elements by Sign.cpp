class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int pi=0;
        int ni=1;
        for(auto& it:nums){
            if(it>0){
                result[pi]=it;
                pi+=2;
            }else{
                result[ni]=it;
                ni+=2;
            }
        }
        return result;
    }
};

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto& it:nums){
            mp2[it]++;
        }

        for(int i=0;i<n;i++){
            int num=nums[i];
            mp1[num]++;
            mp2[num]--;
            int n1=i+1;
            int n2=n-i-1;
            if(mp1[num]*2>n1 and mp2[num]*2>n2){
                return i;
            }
        }
        return -1;
    }
};

//---------------------------------------------------------

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int maj=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                maj=nums[i];
                count=1;
            }else if(nums[i]==maj){
                count++;
            }else{
                count--;
            }
        }

        int majcount=0;
        for(auto& it:nums){
            if(it==maj){
                majcount++;
            }
        }

        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj) count++;
            int rem=majcount-count;
            int n1=i+1;
            int n2=n-i-1;
            if(count*2>n1 and rem*2>n2){
                return i;
            }
        }
        return -1;
    }

};

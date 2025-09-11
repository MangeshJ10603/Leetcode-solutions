class Solution {
public:
    vector<int> subseq(vector<int> nums, int k){
        vector<int> stack;
        int drop=nums.size()-k;
        for(int num:nums){
            while(!stack.empty() and drop>0 and stack.back()<num){
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }
        stack.resize(k);
        return stack;
    }
    vector<int> merge(vector<int> a, vector<int> b){
        vector<int> ans;
        while(!a.empty() || !b.empty()){
            if(a>b){
                ans.push_back(a[0]);
                a.erase(a.begin());
            }else{
                ans.push_back(b[0]);
                b.erase(b.begin());
            }
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> res;
        for(int i=max(0,k-m); i<=min(k,n);i++){
            vector<int> sub1=subseq(nums1,i);
            vector<int> sub2=subseq(nums2,k-i);
            vector<int> merged=merge(sub1,sub2);
            res=max(res,merged);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int drop=n-k;
        vector<int> st;
        for(int num:nums){
            while(!st.empty() and drop>0 and st.back()>num){
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }
        st.resize(k);
        return st;
    }
};

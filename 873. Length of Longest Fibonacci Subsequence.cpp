class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int,int>& mp){
        int target = arr[k]-arr[j];
        if(mp.count(target) and mp[target]<j){
            int i=mp[target];
            return solve(i,j,arr,mp)+1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int max_len=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int length=solve(j,k,arr,mp);
                if(length>=3){
                    max_len = max(max_len,length);
                }
            }
        }
        return max_len;
    }
};

//---------------------------------------------------------------

class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp,vector<vector<int>>& dp) {
        if(dp[j][k]!=-1){
            return dp[j][k];
        }
        int target = arr[k] - arr[j];
        if (mp.count(target) and mp[target] < j) {
            int i = mp[target];
            return dp[j][k]=solve(i, j, arr, mp,dp) + 1;
        }
        return dp[j][k]=2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        int max_len = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp,dp);
                if (length >= 3) {
                    max_len = max(max_len, length);
                }
            }
        }
        return max_len;
    }
};

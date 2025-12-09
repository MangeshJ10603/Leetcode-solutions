class Solution {
public:
    pair<int,int> solve(string& s){
        int zeros=0;
        int ones=0;
        for(char ch:s){
            if(ch-'0'==0) zeros++;
            else ones++;
        }
        return {zeros,ones};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string& s:strs){
            pair<int,int> it=solve(s);
            int zeros=it.first;
            int ones=it.second;
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};

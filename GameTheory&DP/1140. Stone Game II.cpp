class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;
    int solve(int i, int M){
        if(i>=n) return 0;
        if(i+2*M >=n) return suffix[i];
        if(dp[i][M]!=-1) return dp[i][M];
        int best=0;
        for(int x=1;x<=2*M;x++){
            best=max(best,suffix[i]-solve(i+x,max(M,x)));
        }
        return dp[i][M]=best;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffix.assign(n+1,0);
        dp.assign(n,vector<int>(n+1,-1));
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix[i+1]+piles[i];
        }
        return solve(0,1);
    }
};

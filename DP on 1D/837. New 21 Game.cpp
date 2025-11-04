#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    double solve(int N,int K, int W){
        if(K==0) return 1.0;
        if(N>=K+W) return 1.0;
        vector<double> dp(N+1,0.0);
        dp[0]=1.0;
        double windowsum=1.0;
        for(int i=1;i<N;++i){
            dp[i]=windowsum/W;
            if(i<K) windowsum+=dp[i];
            if(i-W>=0) windowsum-=dp[i-W];
        }
        double result=0.0;
        for(int i=K;i<=N;i++){
            result+=dp[i];
        }
        return result;
    }
}

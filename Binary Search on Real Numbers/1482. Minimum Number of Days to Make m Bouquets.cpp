class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int mid){
        int b=0,f=0;
        for(int x:bloomDay){
            if(x<=mid){
                f++;
                if(f==k){
                    b++;
                    f=0;
                }
            }else{
                f=0;
            }
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int total=1LL*m*k;
        if(total>bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(bloomDay,m,k,mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

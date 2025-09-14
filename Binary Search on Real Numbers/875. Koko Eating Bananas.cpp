class Solution {
public:
    bool solve(vector<int>& piles, int mid, int h){
        long long hours=0;
        for(int x:piles){
            hours+=(x+mid-1)/mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int res=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(piles,mid,h)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};

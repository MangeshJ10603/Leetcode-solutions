class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n!=0){
            sum+=pow(n%10,2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1 && st.find(n)==st.end()){
            st.insert(n);
            n=solve(n);
        }
        return n==1;
    }
};

class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];
    bool solve(int idx, string& s){
        if(idx>=n) return true;
        if(t[idx]!=-1) return t[idx];
        if(st.find(s)!=st.end()){
            return t[idx]=true;
        }
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() and solve(idx+l,s)){
                return t[idx]=true;
            }
        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto& it:wordDict){
            st.insert(it);
        }
        memset(t,-1,sizeof(t));
        return solve(0,s);
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string res=s;
        reverse(res.begin(),res.end());
        string l=s+"#"+res;
        int n=l.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int len=lps[i-1];
            while(len>0 and l[i]!=l[len]) len=lps[len-1];
            if(l[i]==l[len]) len++;
            lps[i]=len;
        }
        int m=s.size()-lps[n-1];
        return res.substr(0,m)+s;
    }
};

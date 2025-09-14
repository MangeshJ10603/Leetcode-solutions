class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        int count=0;
        string s="";
        while(s.size()<m){
            s+=a;
            count++;
        }
        if(s.find(b)!=string::npos) return count;
        s+=a;
        if(s.find(b)!=string::npos) return count+1;
        return -1;
    }
};

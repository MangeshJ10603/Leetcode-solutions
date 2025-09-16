class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> res;
        if(s.size() < 10) return res;
        for(int i=0;i+10<=s.size();i++){
            string sub=s.substr(i,10);
            mp[sub]++;
            if(mp[sub]==2) res.push_back(sub);
        }
        return res;
    }
};

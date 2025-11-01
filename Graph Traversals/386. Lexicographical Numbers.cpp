class Solution {
public:
    void solve(int curr, int limit, vector<int>& res){
        if(curr>limit) return;
        res.push_back(curr);
        for(int append=0;append<=9;append++){
            int num=curr*10+append;
            if(num>limit) return;
            solve(num,limit,res);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int start=1; start<=9; start++){
            solve(start,n,res);
        }
        return res;
    }
};

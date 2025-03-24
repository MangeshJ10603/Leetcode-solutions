class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int result=0;
        int start=0;
        int end=0;
        sort(meetings.begin(),meetings.end());
        for(auto& it:meetings){
            int s=it[0];
            int e=it[1];
            if(s>end){
                result+=s-end-1;
            }
            end=max(end,e);
        }

        if(end<days){
            result+=days-end;
        }
        return result;
    }
};

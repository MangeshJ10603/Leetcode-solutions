class Solution {
public:
    int minMaxDifference(int num) {
        string str=to_string(num);
        string str2=str;

        int idx=str.find_first_not_of('9');
        if(idx!=string::npos){
            char ch=str[idx];
            replace(str.begin(),str.end(),ch,'9');
        }

        char ch=str2[0];
        replace(str2.begin(),str2.end(),ch,'0');
        return stoi(str)-stoi(str2);
    }
};

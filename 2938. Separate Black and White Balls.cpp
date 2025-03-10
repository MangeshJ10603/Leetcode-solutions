class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long result = 0;
        int black = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                result += black;
            } else {
                black++;
            }
        }
        return result;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;
        long long prev2 = 1; 
        long long prev1 = 1; 
        for (int i = 2; i <= n; ++i) {
            long long current = 0;
            if (s[i - 1] != '0') {
                current = prev1;
            }
            string two_digits = s.substr(i - 2, 2);
            int val = stoi(two_digits);
            if (val >= 10 && val <= 26) {
                current += prev2;
            }
            if (current == 0) return 0;
            prev2 = prev1;
            prev1 = current;
        }
        return (int)prev1;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);

            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

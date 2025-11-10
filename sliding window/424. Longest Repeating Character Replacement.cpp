class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> char_counts;
        int max_freq = 0;
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            char_counts[s[right]]++;
            max_freq = max(max_freq, char_counts[s[right]]);
            int current_window_length = right - left + 1;
            if (current_window_length - max_freq > k) {
                char_counts[s[left]]--;
                left++;
            }     
            current_window_length = right - left + 1;
            max_len = max(max_len, current_window_length);
        }
        return max_len;
    }
};

class Solution {
private:
    bool isPalindrome(const string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    void backtrack(const string& s, int start, vector<string>& current_partition, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current_partition);
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                current_partition.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current_partition, result);
                current_partition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current_partition;
        backtrack(s, 0, current_partition, result);
        return result;
    }
};

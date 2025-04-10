class Solution {
public:
    long long solve(string& str, string s, int limit) {
        if (str.size() < s.size()) {
            return 0;
        }
        long long count = 0;
        int remL = str.size() - s.size();
        string newStr = str.substr(remL);
        for (int i = 0; i < remL; i++) {
            int digit = str[i] - '0';
            if (digit <= limit) {
                count += digit * pow(limit + 1, remL - i - 1);
            } else {
                count += pow(limit + 1, remL - i);
                return count;
            }
        }

        if (newStr >= s) {
            count += 1;
        }
        return count;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};

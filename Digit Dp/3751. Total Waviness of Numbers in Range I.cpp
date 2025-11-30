class Solution {
private:
    int calculateWaviness(int n) {
        if (n < 100) {
            return 0;
        }
        string s = to_string(n);
        int waviness = 0;
        int len = s.length();
        for (int i = 1; i < len - 1; ++i) {
            int current = s[i] - '0';
            int left = s[i - 1] - '0';
            int right = s[i + 1] - '0';
            if (current > left && current > right) {
                waviness++;
            } 
            else if (current < left && current < right) {
                waviness++;
            }
        }
        return waviness;
    }
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int i = num1; i <= num2; ++i) {
            total += calculateWaviness(i);
        }
        return total;
    }
};

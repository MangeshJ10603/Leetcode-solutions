
class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        int temp = x;
        
        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }
        
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
        
        return (int)reversed;
    }
};

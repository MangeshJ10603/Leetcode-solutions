class Solution {
public:
    int findNthDigit(int n) {
        long long digitlength=1, count=9, start=1;
        while(n>digitlength*count){
            n-=digitlength*count;
            digitlength++;
            count*=10;
            start*=10;
        }
        long long num=start+(n-1)/digitlength;
        string str=to_string(num);
        return str[(n-1)%digitlength]-'0';
    }
};

class Solution {
public:
    bool isPrime(int& num) {
        if (num == 1)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int num = left; num <= right; num++) {
            if(isPrime(num) == true) {
                if (!primes.empty() and num - primes.back() <= 2) {
                    return {primes.back(), num};
                }
                primes.push_back(num);
            }
        }

        vector<int> ans = {-1, -1};
        int min_diff = INT_MAX;
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                ans = {primes[i - 1], primes[i]};
            }
        }
        return ans;
    }
};

// --------------------------------------------------------------


class Solution {
public:
    vector<bool> solve(int right){
        vector<bool> isPrime(right+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(isPrime[i]==true){
                for(int j=2;j*i<=right;j++){
                    isPrime[j*i]=false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = solve(right);
        vector<int> primes;
        for(int num=left; num<=right;num++){
            if(isPrime[num]==true){
                primes.push_back(num);
            }
        }
        vector<int> ans={-1,-1};
        int mindiff = INT_MAX;
        for(int i=1;i<primes.size();i++){
            int diff=primes[i]-primes[i-1];
            if(diff<mindiff){
                mindiff=diff;
                ans={primes[i-1],primes[i]};
            }
        }
        return ans;
    }
};

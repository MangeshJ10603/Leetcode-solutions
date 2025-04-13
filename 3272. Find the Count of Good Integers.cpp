class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;
        for (int num = start; num <= end; num++) {
            string lefthalf = to_string(num);
            string full = "";
            if (n % 2 == 0) {
                string righthalf = lefthalf;
                reverse(righthalf.begin(), righthalf.end());
                full = lefthalf + righthalf;
            } else {
                string righthalf = lefthalf.substr(0, d - 1);
                reverse(righthalf.begin(), righthalf.end());
                full = lefthalf + righthalf;
            }
            long long number = stoll(full);
            if (number % k != 0)
                continue;
            sort(full.begin(), full.end());
            st.insert(full);
        }

        vector<long long> factorial(11, 1);
        for (int i = 1; i < 11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long result = 0;
        for (auto& it : st) {
            vector<int> count(10, 0);
            for (auto& ch : it) {
                count[ch - '0']++;
            }
            int totaldigit = it.size();
            int zerodigits = count[0];
            int nonzerodigits = totaldigit - zerodigits;

            long long per = (nonzerodigits * factorial[totaldigit - 1]);
            for (int i = 0; i < 10; i++) {
                per /= factorial[count[i]];
            }

            result += per;
        }

        return result;
    }
};

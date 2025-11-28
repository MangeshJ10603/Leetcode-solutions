class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) {
            return 0;
        }

        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int chain_length = 0;
        int current_end = -2000000000;

        for (const auto& pair : pairs) {
            if (pair[0] > current_end) {
                chain_length++;
                current_end = pair[1];
            }
        }

        return chain_length;
    }
};

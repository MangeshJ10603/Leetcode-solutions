class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long current_sum = 0;
        long long max_score = 0;
        for (const auto& p : pairs) {
            int num2_val = p.first;
            int num1_val = p.second;
            minHeap.push(num1_val);
            current_sum += num1_val;
            if (minHeap.size() > k) {
                current_sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                max_score = max(max_score, current_sum * num2_val);
            }
        }
        return max_score;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrow_count = 1;
        long long current_end = points[0][1];

        for (size_t i = 1; i < points.size(); ++i) {
            if (points[i][0] > current_end) {
                arrow_count++;
                current_end = points[i][1];
            }
        }
        return arrow_count;
    }
};

class Solution {
public:
    bool solve(vector<int>& ranks, long long mid, int cars) {
        long long carsfixed = 0;
        for (int r : ranks) {
            carsfixed += sqrt(mid / r);
        }
        return carsfixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars, result = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (solve(ranks, mid, cars)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

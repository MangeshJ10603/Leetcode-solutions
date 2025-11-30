
class Solution {
private:
    vector<vector<double>> memo;
    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b] != -1.0) {
            return memo[a][b];
        }
        double prob = 0.0;
        prob += solve(a - 4, b);
        prob += solve(a - 3, b - 1);
        prob += solve(a - 2, b - 2);
        prob += solve(a - 1, b - 3);

        return memo[a][b] = prob * 0.25;
    }
public:
    double soupServings(int N) {
        if (N >= 4800) {
            return 1.0;
        }
        int size = (N + 24) / 25; 
        memo.assign(size + 1, vector<double>(size + 1, -1.0));
        return solve(size, size);
    }
};

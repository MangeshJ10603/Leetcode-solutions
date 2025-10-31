class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if (a == b) continue;

                vector<int> D(n + 1, 0);
                vector<int> pa(n + 1, 0);
                vector<int> pb(n + 1, 0);

                for (int i = 1; i <= n; i++) {
                    int digit = s[i-1] - '0';
                    D[i] = D[i-1] + (digit == a) - (digit == b);
                    pa[i] = (pa[i-1] + (digit == a)) % 2;
                    pb[i] = (pb[i-1] + (digit == b)) % 2;
                }

                vector<vector<int>> best(2, vector<int>(2, INT_MAX));

                for (int j = 0; j <= n; j++) {

                    if (j >= k) {
                        int i = j - k;
                        best[pa[i]][pb[i]] = min(best[pa[i]][pb[i]], D[i]);
                    }

                    int needA = 1 - pa[j];
                    int needB = pb[j];

                    if (best[needA][needB] != INT_MAX) {
                        ans = max(ans, D[j] - best[needA][needB]);
                    }
                }
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};

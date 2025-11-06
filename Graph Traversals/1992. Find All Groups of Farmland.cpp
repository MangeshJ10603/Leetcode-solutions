class Solution {
private:
    int R, C;
    int min_r, min_c, max_r, max_c;
    void dfs(vector<vector<int>>& land, int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || land[r][c] != 1) {
            return;
        }
        land[r][c] = 2;
        min_r = min(min_r, r);
        min_c = min(min_c, c);
        max_r = max(max_r, r);
        max_c = max(max_c, c);
        dfs(land, r + 1, c);
        dfs(land, r - 1, c);
        dfs(land, r, c + 1);
        dfs(land, r, c - 1);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        R = land.size();
        C = land[0].size();
        vector<vector<int>> result;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (land[r][c] == 1) {
                    min_r = r;
                    min_c = c;
                    max_r = r;
                    max_c = c;
                    dfs(land, r, c);
                    result.push_back({min_r, min_c, max_r, max_c});
                }
            }
        }
        return result;
    }
};

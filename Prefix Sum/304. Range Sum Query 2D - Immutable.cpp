class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int R = matrix.size();
        int C = matrix[0].size();       
        prefixSum.resize(R + 1, vector<int>(C + 1, 0));
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                prefixSum[r + 1][c + 1] = matrix[r][c] + prefixSum[r][c + 1] + prefixSum[r + 1][c] - prefixSum[r][c];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (prefixSum.empty()) {
            return 0;
        }
        row1++; 
        col1++; 
        row2++; 
        col2++;
        return prefixSum[row2][col2] - prefixSum[row1 - 1][col2] - prefixSum[row2][col1 - 1] + prefixSum[row1 - 1][col1 - 1];
    }
};

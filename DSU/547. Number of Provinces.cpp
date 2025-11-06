class Solution {
private:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    unite(i, j);
                }
            }
        }
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                provinces++;
            }
        }
        return provinces;
    }
};

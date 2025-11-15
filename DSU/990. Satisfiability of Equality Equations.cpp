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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0] - 'a') == find(eq[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};

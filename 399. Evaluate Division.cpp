class Solution {
public:
    void solve(unordered_map<string, vector<pair<string, double>>>& adj, string& src, string& des, double& ans, double prod, unordered_set<string>& visited) {
        if (visited.count(src)) return;
        visited.insert(src);
        if (src == des) {
            ans = prod;
            return;
        }
        for (auto& it : adj[src]) {
            string v = it.first;
            double val = it.second;
            solve(adj, v, des, ans, prod * val, visited);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].emplace_back(v, val);
            adj[v].emplace_back(u, 1.0 / val);
        }
        vector<double> result;
        for (auto& it : queries) {
            string src = it[0];
            string des = it[1];
            double ans = -1.0;
            if (adj.count(src) && adj.count(des)) {
                unordered_set<string> visited;
                solve(adj, src, des, ans, 1.0, visited);
            }
            result.push_back(ans);
        }
        return result;
    }
};

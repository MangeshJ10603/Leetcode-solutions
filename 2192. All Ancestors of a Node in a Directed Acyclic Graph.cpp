class Solution {
public:
    void dfs(int ancestor, unordered_map<int,vector<int>>& adj, int curr, vector<vector<int>>& result){
        for(auto& ngbr : adj[curr]){
            if (result[ngbr].empty() || result[ngbr].back() != ancestor) { 
                result[ngbr].push_back(ancestor);
                dfs(ancestor, adj, ngbr, result);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            dfs(i, adj, i, result);
        }

        return result;
    }
};


// ----------------------------------------------------------------------


class Solution {
public:
    void dfs(int curr, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[curr] = true;
        for (auto& ngbr : adj[curr]) {
            if(!visited[ngbr]){
                dfs(ngbr,adj,visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            vector<int> ancestor;
            vector<bool> visited(n, false);
            dfs(i, adj, visited);
            for (int j = 0; j < n; j++) {
                if (j != i && visited[j]) {
                    ancestor.push_back(j);
                }
            }
            result[i] = ancestor;
        }

        return result;
    }
};

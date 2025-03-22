class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        void Union(int x, int y) {
            int par_x = find(x), par_y = find(y);
            if (par_x == par_y) return;
            if (size[par_x] > size[par_y]) {
                parent[par_y] = par_x;
                size[par_x] += size[par_y];
            } else {
                parent[par_x] = par_y;
                size[par_y] += size[par_x];
            }
        }
    };
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> mp;
        
        for (auto& it : edges) dsu.Union(it[0], it[1]);
        for (auto& it : edges) mp[dsu.find(it[0])]++;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                int v = dsu.size[i], e = mp[i];
                if ((v * (v - 1))/2 == e) res++;
            }
        }
        return res;
    }
};


//---------------------------------------------------------------------

class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited,
             int& v, int& e) {
                visited[i]=true;
                v++;
                e+=adj[i].size();
                for(auto& it:adj[i]){
                    if(!visited[it]){
                        dfs(it,adj,visited,v,e);
                    }
                }
             }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int count = 0;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == true)
                continue;
            int v = 0;
            int e = 0;
            dfs(i, adj, visited, v, e);
            if ((v * (v - 1)) == e) {
                count++;
            }
        }
        return count;
    }
};


//------------------------------------------------------------------


class Solution {
public:
    void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited,
             int& v, int& e) {
                queue<int> q;
                q.push(i);
                visited[i]=true;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    v++;
                    e+=adj[node].size();
                    for(auto& it:adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it]=true;
                        }
                    }
                }
             }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int count = 0;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == true)
                continue;
            int v = 0;
            int e = 0;
            bfs(i, adj, visited, v, e);
            if ((v * (v - 1)) == e) {
                count++;
            }
        }
        return count;
    }
};

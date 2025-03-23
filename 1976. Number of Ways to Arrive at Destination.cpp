class Solution {
public:
    int MOD = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& it : roads) {
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathcount(n, 0);
        result[0] = 0;
        pathcount[0] = 1;
        
        while (!pq.empty()) {
            long long currtime = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();
            
            for (auto& it : adj[currnode]) {
                int ngbr = it.first, roadtime = it.second;
                if (roadtime + currtime < result[ngbr]) {
                    result[ngbr] = currtime + roadtime;
                    pq.push({result[ngbr], ngbr});
                    pathcount[ngbr] = pathcount[currnode];
                } else if (roadtime + currtime == result[ngbr]) {
                    pathcount[ngbr] = (pathcount[ngbr] + pathcount[currnode]) % MOD;
                }
            }
        }
        
        return pathcount[n - 1];
    }
};

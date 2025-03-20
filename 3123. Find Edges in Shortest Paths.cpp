#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(vector<vector<pair<int, long long>>>& adj, int src, int n) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            long long wt = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();

            if (wt > dist[currnode]) continue;

            for (auto& it : adj[currnode]) {
                int nextnode = it.first;
                long long nextwt = it.second;
                if (dist[nextnode] > wt + nextwt) {
                    dist[nextnode] = wt + nextwt;
                    pq.push({dist[nextnode], nextnode});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, long long>>> adj(n); 

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            long long w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> fromSrc = solve(adj, 0, n);
        vector<long long> fromDest = solve(adj, n - 1, n);
        vector<bool> result(edges.size(), false);

        if (fromSrc[n - 1] == LLONG_MAX) return result; 

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2];

            if ((fromSrc[u] != LLONG_MAX && fromDest[v] != LLONG_MAX && fromSrc[u] + w + fromDest[v] == fromSrc[n - 1]) || 
                (fromSrc[v] != LLONG_MAX && fromDest[u] != LLONG_MAX && fromSrc[v] + w + fromDest[u] == fromSrc[n - 1])) {
                result[i] = true;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int Q = queries.size();
        vector<pair<int, int>> res;
        vector<int> result(Q, 0);
        
        for (int i = 0; i < Q; i++) {
            res.push_back({queries[i], i});
        }
        
        sort(res.begin(), res.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        for (int i = 0; i < Q; i++) {
            int val = res[i].first;
            int idx = res[i].second;
            
            while (!pq.empty() && pq.top()[0] < val) {
                int x = pq.top()[1];
                int y = pq.top()[2];
                pq.pop();
                points++;

                for (auto& d : dir) {
                    int xx = x + d[0];
                    int yy = y + d[1];
                    if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy]) {
                        pq.push({grid[xx][yy], xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
            result[idx] = points;
        }
        return result;
    }
};

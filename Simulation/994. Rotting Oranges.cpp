class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, minutes = 0;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};

        while(!q.empty() && fresh > 0){
            int sz = q.size();
            while(sz--){
                auto [x,y] = q.front(); q.pop();
                for(auto &d: dir){
                    int xx = x + d[0], yy = y + d[1];
                    if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy] == 1){
                        grid[xx][yy] = 2;  
                        fresh--;
                        q.push({xx,yy});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};

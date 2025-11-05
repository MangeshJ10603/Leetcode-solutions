class Solution{
public:
    int solve(vector<vector<int>>& grid){
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty()){
            auto [r,c,dist]=q.front();
            q.pop();
            if(r==n-1 && c==n-1) return dist;
            for(auto& d:dir){
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc,dist+1});
                }
            }
        }
        return -1;
    }
}

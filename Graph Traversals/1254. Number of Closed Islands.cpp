class Solution {
public:
    int m,n;
    bool solve(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(grid[i][j]==1) return true;
        grid[i][j]=1;
        bool left=solve(grid,i,j-1);
        bool right=solve(grid,i,j+1);
        bool up=solve(grid,i-1,j);
        bool down=solve(grid,i+1,j);
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    if(solve(grid,i,j)==true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

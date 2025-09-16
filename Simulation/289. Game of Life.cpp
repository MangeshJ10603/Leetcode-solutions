class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        
        vector<vector<int>> res = board;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int lives=0;
                for(auto& d:dir){
                    int x=i+d[0];
                    int y=j+d[1];
                    if(x>=0 && x<n && y>=0 && y<m && board[x][y]==1){
                        lives++;
                    }
                }
                if(board[i][j]==1 && (lives<2 || lives>3)) res[i][j]=0;
                else if(board[i][j]==0 && lives==3) res[i][j]=1; 
            }
        }
        
        board = res;
    }
};

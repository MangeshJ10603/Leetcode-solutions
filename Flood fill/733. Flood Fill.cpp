class Solution {
public: 
    void solve(vector<vector<int>>& image, int r, int c, int color, int newcolor){
        int n=image.size();
        int m=image[0].size();
        if(r<0 || r>=n || c<0 || c>=m || image[r][c]!=color){
            return;
        }
        image[r][c]=newcolor;
        solve(image,r+1,c,color,newcolor);
        solve(image,r-1,c,color,newcolor);
        solve(image,r,c+1,color,newcolor);
        solve(image,r,c-1,color,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor!=color){
            solve(image,sr,sc,oldcolor,color);
        }
        return image;
    }
};

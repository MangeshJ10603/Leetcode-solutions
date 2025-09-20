class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
        int count=1;
        int top=0;
        int down=n-1;
        int left=0;
        int right=n-1;
        int d=0;
        vector<vector<int>> result(n,vector<int>(n,-1));
        while(left<=right and top<=down){
            if(d==0){
                for(int i=left; i<=right; i++){
                    result[top][i]=count++;
                }
                top++;
            }
            if(d==1){
                for(int i=top;i<=down;i++){
                    result[i][right]=count++;
                }
                right--;
            }
            if(d==2){
                for(int i=right;i>=left;i--){
                    result[down][i]=count++;
                }
                down--;
            }
            if(d==3){
                for(int i=down;i>=top;i--){
                    result[i][left]=count++;
                }
                left++;
            }
            d=(d+1)%4;
        }
        return result;
    }
};

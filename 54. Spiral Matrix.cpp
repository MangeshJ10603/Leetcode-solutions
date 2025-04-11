class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> result;
        int d=0;
        int top=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        while(left<=right and top<=down){
            if(d==0){
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(d==1){
                for(int i=top; i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(d==2){
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            if(d==3){
                for(int i=down; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            d=(d+1)%4;
        }
        return result;
    }
};

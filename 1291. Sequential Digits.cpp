class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1;i<=8;i++){
            q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp>=low and temp<=high){
                result.push_back(temp);
            }
            int lastdigit=temp%10;
            if(lastdigit+1<=9){
                q.push(temp*10+lastdigit+1);
            }
        }
        return result;
    }

};

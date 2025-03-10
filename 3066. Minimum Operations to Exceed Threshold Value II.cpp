class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>> pq(nums.begin(),nums.end());
        int count=0;
        while(!pq.empty() and pq.top()<k){
            long smallest=pq.top();
            pq.pop();
            long ssmallest=pq.top();
            pq.pop();
            pq.push(smallest*2+ssmallest);
            count++;
        }
        return count;
    }
};

//--------------------------------------------------------------------------------

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0, j = 0, count = 0, x, y; ; ++count) {
            if (i < a.size() && (j >= b.size() || a[i] <= b[j])) x = a[i++];
            else x = b[j++];
            if (x >= k) return count;
            if (i < a.size() && (j >= b.size() || a[i] <= b[j])) y = a[i++];
            else y = b[j++];
            long t = 2L * x + y;
            b.push_back(t < k ? (int)t : k);
        }
        return -1;
    }
};

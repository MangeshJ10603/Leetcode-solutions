class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> res(nums.begin(), nums.end());
        sort(res.begin(), res.end());
        
        unordered_map<int, int> groupMap;
        int group = 0;
        groupMap[res[0]] = group;

        unordered_map<int, deque<int>> groupValues;
        groupValues[group].push_back(res[0]);

        for (int i = 1; i < n; i++) {
            if (res[i] - res[i - 1] > limit) {
                group += 1;
            }
            groupMap[res[i]] = group;
            groupValues[group].push_back(res[i]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int grp = groupMap[val];
            ans[i] = groupValues[grp].front();
            groupValues[grp].pop_front();
        }

        return ans;
    }
};

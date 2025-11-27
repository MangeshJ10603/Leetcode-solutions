class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> counts;
        for (char task : tasks) {
            counts[task]++;
        }
        priority_queue<int> pq;
        for (auto const& [key, val] : counts) {
            pq.push(val);
        }
        int cycles = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int time = 0;
            
            for (int i = 0; i <= n; ++i) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }
            for (int count : temp) {
                if (count > 0) {
                    pq.push(count);
                }
            }

            if (pq.empty()) {
                cycles += time;
            } else {
                cycles += n + 1;
            }
        }

        return cycles;
    }
};

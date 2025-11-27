class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto const& [key, val] : counts) {
            if (val > (s.length() + 1) / 2) {
                return "";
            }
            pq.push({val, key});
        }

        string result = "";
        
        while (pq.size() >= 2) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();

            result += p1.second;
            result += p2.second;

            if (--p1.first > 0) {
                pq.push(p1);
            }
            if (--p2.first > 0) {
                pq.push(p2);
            }
        }

        if (!pq.empty()) {
            result += pq.top().second;
        }

        return result;
    }
};

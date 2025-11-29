
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> min_cost(n, 1e9);
        min_cost[src] = 0;

        for (int stops = 0; stops <= k; ++stops) {
            vector<int> temp_cost = min_cost;
            bool updated = false;

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (min_cost[u] != 1e9) {
                    if (temp_cost[v] > min_cost[u] + price) {
                        temp_cost[v] = min_cost[u] + price;
                        updated = true;
                    }
                }
            }
            min_cost = temp_cost;
            
            if (!updated && min_cost[dst] != 1e9) {
                break;
            }
        }

        return min_cost[dst] == 1e9 ? -1 : min_cost[dst];
    }
};

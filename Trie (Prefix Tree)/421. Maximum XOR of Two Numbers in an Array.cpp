struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};
class Solution {
private:
    TrieNode* root;
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 30; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit;

            if (node->children[opposite_bit]) {
                maxXOR |= (1 << i);
                node = node->children[opposite_bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (int num : nums) {
            insert(num);
        }
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, findMaxXOR(num));
        }
        return max_val;
    }
};

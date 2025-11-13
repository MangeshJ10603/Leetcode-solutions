class Solution {
private:
    int totalSum = 0;

    void dfs(TreeNode* node, int currentNumber) {
        if (!node) {
            return;
        }

        currentNumber = currentNumber * 10 + node->val;

        if (!node->left && !node->right) {
            totalSum += currentNumber;
            return;
        }

        dfs(node->left, currentNumber);
        dfs(node->right, currentNumber);
    }

public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return totalSum;
    }
};

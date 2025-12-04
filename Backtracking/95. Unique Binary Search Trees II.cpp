class Solution {
private:
    vector<TreeNode*> generateTreesRecursive(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = generateTreesRecursive(start, i - 1);
            vector<TreeNode*> rightTrees = generateTreesRecursive(i + 1, end);
            for (TreeNode* leftRoot : leftTrees) {
                for (TreeNode* rightRoot : rightTrees) {
                    TreeNode* currentRoot = new TreeNode(i, leftRoot, rightRoot);
                    allTrees.push_back(currentRoot);
                }
            }
        }
        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesRecursive(1, n);
    }
};

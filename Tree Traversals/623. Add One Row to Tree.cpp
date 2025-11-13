class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        while (!q.empty()) {
            if (currentDepth == depth - 1) {
                while (!q.empty()) {
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* newLeft = new TreeNode(val, node->left, nullptr);
                    TreeNode* newRight = new TreeNode(val, nullptr, node->right);
                    node->left = newLeft;
                    node->right = newRight;
                }
                return root;
            }
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            currentDepth++;
        }
        return root;
    }
};

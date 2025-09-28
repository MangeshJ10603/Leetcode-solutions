/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; 
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                
                int idx = flag ? (n - i - 1) : i;
                temp[idx] = t->val;
                
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            
            result.push_back(temp);
            flag = !flag; 
        }
        
        return result;
    }
};

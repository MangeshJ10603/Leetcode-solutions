class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        int take=root->val+left.second+right.second;
        int skip=max(left.first,left.second)+max(right.first,right.second);
        return {take,skip};
    }
    int rob(TreeNode* root) {
        pair<int,int> result=solve(root);
        return max(result.first,result.second);
    }
};

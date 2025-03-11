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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childset;
        for(auto& it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isleft==1){
                mp[parent]->left=mp[child];
            }else{
                mp[parent]->right=mp[child];
            }
            childset.insert(child);
        }

        for(auto& it:descriptions){
            int parent = it[0];
            if(childset.find(parent)==childset.end()){
                return mp[parent];
            }
        }
        return nullptr;
    }
};

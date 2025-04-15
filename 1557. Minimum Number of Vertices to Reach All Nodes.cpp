class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n,false);
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            indegree[v]=true;
        }
        vector<int> result;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==false){
                result.push_back(i);
            }
        }
        return result;
    }
};

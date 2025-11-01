class Solution {
public:
    bool solve(vector<vector<int>>& graph, int curr, vector<int>& colors, int currcolor){
        colors[curr]=currcolor;
        for(auto& v:graph[curr]){
            if(colors[v]==currcolor){
                return false;
            }
            if(colors[v]==-1 and !solve(graph,v,colors,1-currcolor)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> colors(v,-1);
        for(int i=0;i<v;i++){
            if(colors[i]==-1 and !solve(graph,i,colors,1)){
                return false;
            }
        }
        return true;
    }
};

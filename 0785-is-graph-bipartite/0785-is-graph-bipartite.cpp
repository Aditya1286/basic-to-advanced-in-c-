class Solution {
private:
    bool dfs(int node,int color,vector<vector<int>>&adj,vector<int>& visited){
        visited[node]=color;
        for(auto nodi:adj[node]){
            if(visited[nodi]==-1){
                if(!dfs(nodi,!color,adj,visited))return false;
            }
            else if(visited[nodi]==color)return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> visited(v,-1);
        for(int i=0;i<v;i++){
            if(visited[i]==-1){
                if(!dfs(i,0,graph,visited))return false;
            }
        }
        return true;
    }
};
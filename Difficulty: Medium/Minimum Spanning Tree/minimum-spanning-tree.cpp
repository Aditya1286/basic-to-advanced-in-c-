class Solution {
  public:
    typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> visited(V,0);
        priority_queue<P,vector<P>,greater<P> > pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            int dist=current.first;
            int node=current.second;
            if(visited[node])continue;
            visited[node]=1;
            sum+=dist;
            for(auto it:adj[node]){
                int adjw=it.second;
                int adjnode=it.first;
                if(!visited[adjnode]){
                    pq.push({adjw,adjnode});
                }
                
            }
        }
        return sum;
        
    }
};
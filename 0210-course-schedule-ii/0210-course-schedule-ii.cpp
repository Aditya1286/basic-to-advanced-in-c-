class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        queue<int> q;
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);   
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        int count=0;
        while(!q.empty()){
            int current=q.front();
            q.pop();
            ans.push_back(current);
            count++;
            for(auto it:adj[current]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==n){
            return ans;
        }
        else return {};
    }
};
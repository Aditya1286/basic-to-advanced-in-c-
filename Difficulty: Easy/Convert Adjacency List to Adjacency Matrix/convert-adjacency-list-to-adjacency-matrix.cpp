class Solution {
  public:
    vector<vector<int>> adjToMat(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int m=adj[i].size();
            for(int j=0;j<m;j++){
                arr[i][adj[i][j]]=1;
            }
        }
        return arr;
    }
};
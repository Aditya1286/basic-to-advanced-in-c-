class Solution {
private:
    int dfs(int i,int j, vector<vector<int>>&grid,vector<vector<int>>& visited){
        int row=grid.size();
        int col=grid[0].size();
        if(i<0 || j<0 || i>=row || j>=col)return 0;
        if(grid[i][j]==0)return 0;
        if(visited[i][j]==1)return 0;
        visited[i][j]=1;
        return 1+dfs(i+1,j,grid,visited) + dfs(i-1,j,grid,visited) + dfs(i,j+1,grid,visited) + dfs(i,j-1,grid,visited);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    int a=dfs(i,j,grid,visited);
                    ans=max(ans,a);
                }
            }
        }
        return ans;
    }
};
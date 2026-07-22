class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){
        int row=grid.size();
        int col=grid[0].size();
        if(i<0 || j<0 || i>=row || j>=col ) return;
        if(grid[i][j]=='0')return;
        if(visited[i][j]==1)return;
        visited[i][j]=1;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> visited(row,vector<int>(col,0));
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};
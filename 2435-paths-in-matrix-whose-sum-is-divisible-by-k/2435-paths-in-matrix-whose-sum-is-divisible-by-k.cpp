class Solution {
public:
    int mod=1e9+7;
    bool isvalid(int n,int m,int i,int j){
        return i<n && j<m;
    }
    int solve(vector<vector<int>> & grid,int i,int j,int k , int sum,vector<vector<vector<int>>> & dp){
        if(!isvalid(grid.size(),grid[0].size(),i,j)) return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            sum+=grid[i][j];
            return sum%k==0;
        }
        int rem=sum%k;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        int pickright=solve(grid,i,j+1,k,rem+grid[i][j],dp);
        int pickdown=solve(grid,i+1,j,k,rem+grid[i][j],dp);
        return dp[i][j][rem] = (pickright+pickdown)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int>(k,-1)));
        return solve(grid,0,0,k,0,dp);
        
    }
};
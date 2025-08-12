class Solution {
public:
    vector<string> ans;

    void solve(int i, int j, vector<vector<int>>& arr, int n, string move, vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        // Down
        if (i + 1 < n && vis[i + 1][j] == 0 && arr[i + 1][j] == 1) {
            vis[i + 1][j] = 1;
            solve(i + 1, j, arr, n, move + "D", vis);
            vis[i + 1][j] = 0;
        }
        // Left
        if (j - 1 >= 0 && vis[i][j - 1] == 0 && arr[i][j - 1] == 1) {
            vis[i][j - 1] = 1;
            solve(i, j - 1, arr, n, move + "L", vis);
            vis[i][j - 1] = 0;
        }
        // Right
        if (j + 1 < n && vis[i][j + 1] == 0 && arr[i][j + 1] == 1) {
            vis[i][j + 1] = 1;
            solve(i, j + 1, arr, n, move + "R", vis);
            vis[i][j + 1] = 0;
        }
        // Up
        if (i - 1 >= 0 && vis[i - 1][j] == 0 && arr[i - 1][j] == 1) {
            vis[i - 1][j] = 1;
            solve(i - 1, j, arr, n, move + "U", vis);
            vis[i - 1][j] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (maze[0][0] == 0) return {}; 
        vis[0][0] = 1;
        solve(0, 0, maze, n, "", vis);
        return ans;
    }
};

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int countFresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (mat[i][j] == 1) countFresh++;
            }
        }

        int tm = 0, cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == 0 && mat[row][col] == 1) {
                    q.push({{row, col}, t + 1});
                    vis[row][col] = 2;
                    cnt++;
                }
            }
        }

        if (cnt != countFresh) return -1;
        return tm;
    }
};

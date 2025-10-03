class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<>> pq;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        int water = 0;
        vector<int> dir = {0,1,0,-1,0};

        while (!pq.empty()) {
            auto [h, cell] = pq.top(); pq.pop();
            int x = cell.first, y = cell.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d], ny = y + dir[d+1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                water += max(0, h - heightMap[nx][ny]);
                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return water;
    }
};

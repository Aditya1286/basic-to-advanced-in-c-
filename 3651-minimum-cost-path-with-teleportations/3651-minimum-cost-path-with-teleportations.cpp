class Solution {
public:
    typedef pair<int, pair<int, pair<int,int>>> P;

    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX))
        );

        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end());

        vector<int> ptr(k + 1, 0);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, {0, 0}}});
        dist[0][0][0] = 0;

        vector<vector<int>> dir = {{0,1}, {1,0}};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int used = top.second.first;
            int x = top.second.second.first;
            int y = top.second.second.second;

            if (x == n - 1 && y == m - 1) return cost;
            if (cost > dist[x][y][used]) continue;

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < n && ny < m) {
                    int ncost = cost + grid[nx][ny];
                    if (ncost < dist[nx][ny][used]) {
                        dist[nx][ny][used] = ncost;
                        pq.push({ncost, {used, {nx, ny}}});
                    }
                }
            }

            if (used < k) {
                while (ptr[used] < cells.size() &&
                       get<0>(cells[ptr[used]]) <= grid[x][y]) {

                    int i = get<1>(cells[ptr[used]]);
                    int j = get<2>(cells[ptr[used]]);

                    if (cost < dist[i][j][used + 1]) {
                        dist[i][j][used + 1] = cost;
                        pq.push({cost, {used + 1, {i, j}}});
                    }
                    ptr[used]++;
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);
        
        auto getBoardValue = [&](int num) {
            int r = (num - 1) / n;
            int c = (num - 1) % n;
            if (r % 2 == 1) c = n - 1 - c;
            r = n - 1 - r;
            return board[r][c];
        };
        
        queue<pair<int, int>> q;
        q.push({1, 0}); 
        visited[1] = 1;

        while (!q.empty()) {
            auto [square, moves] = q.front(); q.pop();

            if (square == n * n) return moves;

            for (int i = 1; i <= 6 && square + i <= n * n; ++i) {
                int next = square + i;
                int val = getBoardValue(next);
                if (val != -1) next = val;
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};

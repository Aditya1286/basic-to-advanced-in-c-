class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        for (auto& query : queries) {
            int r1 = query[0], c1 = query[1], r2 = query[2], c2 = query[3];
            mat[r1][c1] += 1;
            if (r2 + 1 < n) mat[r2 + 1][c1] -= 1;
            if (c2 + 1 < n) mat[r1][c2 + 1] -= 1;
            if (r2 + 1 < n && c2 + 1 < n) mat[r2 + 1][c2 + 1] += 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                mat[i][j] += mat[i - 1][j];
            }
        }

        return mat;
    }
};

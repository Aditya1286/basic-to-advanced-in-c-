class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int row = 0; row < n; row++) {
            vector<int> diagonal;
            for (int r = row, c = 0; r < n && c < n; r++, c++) {
                diagonal.push_back(grid[r][c]);
            }
            sort(diagonal.rbegin(), diagonal.rend());
            int idx = 0;
            for (int r = row, c = 0; r < n && c < n; r++, c++) {
                grid[r][c] = diagonal[idx++];
            }
        }

        for (int col = 1; col < n; col++) {
            vector<int> diagonal;
            for (int r = 0, c = col; r < n && c < n; r++, c++) {
                diagonal.push_back(grid[r][c]);
            }
            sort(diagonal.begin(), diagonal.end());
            int idx = 0;
            for (int r = 0, c = col; r < n && c < n; r++, c++) {
                grid[r][c] = diagonal[idx++];
            }
        }

        return grid;
    }
};

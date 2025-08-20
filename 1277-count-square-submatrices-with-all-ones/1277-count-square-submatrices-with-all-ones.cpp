class Solution {
public:
   bool isSquare(vector<vector<int>>& matrix, int i, int j, int size) {
        int m = matrix.size(), n = matrix[0].size();
        if (i + size > m || j + size > n) return false; 
        for (int x = i; x < i + size; x++) {
            for (int y = j; y < j + size; y++) {
                if (matrix[x][y] == 0) return false;
            }
        }
        return true;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int maxSize = min(m - i, n - j);
                    for (int size = 1; size <= maxSize; size++) {
                        if (isSquare(matrix, i, j, size)) {
                            total++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return total;
    }
};

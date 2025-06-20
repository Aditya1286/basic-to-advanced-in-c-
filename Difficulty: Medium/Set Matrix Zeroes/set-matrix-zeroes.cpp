class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        bool firstRow = false, firstCol = false;
        
        for (int i = 0; i < rows; i++) {
            if (mat[i][0] == 0) firstCol = true;
        }

        for (int j = 0; j < cols; j++) {
            if (mat[0][j] == 0) firstRow = true;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                mat[0][j] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < rows; i++) {
                mat[i][0] = 0;
            }
        }
    }
};
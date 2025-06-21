class Solution {
  public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;
        int index = 0;

        while (top <= bottom && left <= right && index < arr.size()) {
            for (int i = left; i <= right && index < arr.size(); i++) {
                matrix[top][i] = arr[index++];
            }
            top++;

            for (int i = top; i <= bottom && index < arr.size(); i++) {
                matrix[i][right] = arr[index++];
            }
            right--;

            for (int i = right; i >= left && index < arr.size(); i--) {
                matrix[bottom][i] = arr[index++];
            }
            bottom--;

            for (int i = bottom; i >= top && index < arr.size(); i--) {
                matrix[i][left] = arr[index++];
            }
            left++;
        }

        return matrix;
    }
};

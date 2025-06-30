class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mat[i][mid] == x) return true;
                else if (mat[i][mid] < x) low = mid + 1;
                else high = mid - 1;
            }
        }
        
        return false;
    }
};

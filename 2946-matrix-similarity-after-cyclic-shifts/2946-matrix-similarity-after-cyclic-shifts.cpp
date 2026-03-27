class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        k = k % m;  
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int newIndex;
                
                if (i % 2 == 0) {
                   newIndex = (j - k + m) % m;
                } else {
                    newIndex = (j + k) % m;
                }
                
                if (mat[i][j] != mat[i][newIndex]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        int low = 1, high = 1e9;
        int desired = (r * c + 1) / 2;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            int cnt = 0;
            for(int i = 0; i < r; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(cnt < desired) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};

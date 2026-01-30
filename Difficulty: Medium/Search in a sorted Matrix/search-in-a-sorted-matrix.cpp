class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int target) {
        int ROW=mat.size();
        int COL=mat[0].size();
        int low=0;
        int high=ROW*COL-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/COL ;
            int col=mid%COL;
            if(mat[row][col]<target){
                low=mid+1;
            }
            else if(mat[row][col]>target){
                high=mid-1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
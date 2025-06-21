
class Solution {
  public:
    void rotateby90(vector<vector<int>>& arr) {
        int n=arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int j=0;j<n;j++){
        int top=0;
        int bottom=n-1;
        while(top<bottom){
            swap(arr[top][j],arr[bottom][j]);
            top++;
            bottom--;
        }
    }
    }
};

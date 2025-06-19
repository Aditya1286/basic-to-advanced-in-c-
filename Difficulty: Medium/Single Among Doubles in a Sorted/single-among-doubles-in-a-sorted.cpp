class Solution {
  public:
    int findOnce(vector<int>& arr) {
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            c^=arr[i];
        }
        return c;
    }
};
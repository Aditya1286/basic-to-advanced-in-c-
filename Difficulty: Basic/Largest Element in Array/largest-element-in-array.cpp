class Solution {
  public:
    int largest(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size()-1;
        return arr[n];
    }
};

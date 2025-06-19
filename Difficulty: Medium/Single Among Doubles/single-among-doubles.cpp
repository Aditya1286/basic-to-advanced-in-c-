// User function template for C++
class Solution {
  public:
    int search(int n, int arr[]) {
        int c=0;
        for(int i=0;i<n;i++){
            c^=arr[i];
        }
        return c;
    }
};
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int maxi = INT_MIN;
        int pre = 1, sufi = 1;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (sufi == 0) sufi = 1;

            pre *= arr[i];
            sufi *= arr[n - 1 - i]; 

            maxi = max({maxi, pre, sufi});
        }

        return maxi;
    }
};

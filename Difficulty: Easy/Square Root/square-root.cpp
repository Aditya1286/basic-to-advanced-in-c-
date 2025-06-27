class Solution {
  public:
    int floorSqrt(int n) {
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)mid * mid == n) return mid;

            if ((long long)mid * mid < n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    bool possible(vector<int>& arr, int days, int m, int k) {
        int count = 0, bouquets = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDaysBloom(int m, int k, vector<int> &arr) {
        if (1LL * m * k > arr.size()) return -1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

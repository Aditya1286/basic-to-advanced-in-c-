class Solution {
  public:
    bool isPossible(int arr[], int n, int cap, int d) {
        int days = 1, load = 0;
        for (int i = 0; i < n; i++) {
            if (load + arr[i] > cap) {
                days++;
                load = 0;
            }
            load += arr[i];
        }
        return days <= d;
    }

    int leastWeightCapacity(int arr[], int n, int d) {
        int low = *max_element(arr, arr + n);
        int high = accumulate(arr, arr + n, 0);
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(arr, n, mid, d)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

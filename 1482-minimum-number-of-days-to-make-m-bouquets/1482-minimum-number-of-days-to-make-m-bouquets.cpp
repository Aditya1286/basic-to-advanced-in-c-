class Solution {
public:
    bool possible(vector<int> arr, int days, int m, int k) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) {
                count++;
            } else {
                ans += (count / k);
                count = 0;
            }
        }
        ans += (count / k);
        return ans >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        if (1LL * m * k > arr.size()) return -1;
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }
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

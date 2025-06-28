class Solution {
public:
    bool possible(vector<int> &arr, int cap, int d) {
        int load = 0, days = 1;
        for (int weight : arr) {
            if (load + weight > cap) {
                days++;
                load = 0;
            }
            load += weight;
        }
        return days <= d;
    }

    int shipWithinDays(vector<int>& arr, int d) {
        int low = 0, high = 0;
        for (int i = 0; i < arr.size(); i++) {
            high += arr[i];
            low = max(low, arr[i]);
        }

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(arr, mid, d)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

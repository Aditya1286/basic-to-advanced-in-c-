class Solution {
public:
    long long asd(vector<int> &piles, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1LL) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long time = asd(arr, mid);

            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

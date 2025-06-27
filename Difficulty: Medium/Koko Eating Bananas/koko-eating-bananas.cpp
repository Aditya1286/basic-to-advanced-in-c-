class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int ans = high;

        auto hoursNeeded = [&](int speed) {
            int hours = 0;
            for (int bananas : arr) {
                hours += (bananas + speed - 1) / speed;
            }
            return hours;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int time = hoursNeeded(mid);

            if (time <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

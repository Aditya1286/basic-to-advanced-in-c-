class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int students = 1, sum = 0;
        for (int pages : arr) {
            if (pages > maxPages) return false;
            if (sum + pages > maxPages) {
                students++;
                sum = pages;
            } else {
                sum += pages;
            }
        }
        return students <= k;
    }

    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
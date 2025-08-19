class Solution {
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        return atMost(arr, target) - atMost(arr, target - 1);
    }

  private:
    int atMost(vector<int>& arr, int target) {
        if (target < 0) return 0;
        int left = 0, sum = 0, res = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }
};

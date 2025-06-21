class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int closestSum = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];

                int diffNew = abs(sum - target);
                int diffOld = abs(closestSum - target);

                if (diffNew < diffOld || (diffNew == diffOld && sum > closestSum)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return closestSum;
    }
};

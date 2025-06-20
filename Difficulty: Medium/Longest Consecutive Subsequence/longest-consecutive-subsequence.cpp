class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0;

        int count = 1;
        int longest = 1;

        sort(arr.begin(), arr.end());
        int least_element = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                continue;
            }
            if (arr[i] - 1 == least_element) {
                count++;
            } else {
                count = 1;
            }
            least_element = arr[i];
            longest = max(longest, count);
        }
        return longest;
    }
};

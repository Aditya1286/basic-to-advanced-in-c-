class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& arr, int left, int right) {
        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

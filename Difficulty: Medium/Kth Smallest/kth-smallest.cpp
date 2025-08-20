class Solution {
  public:
    int kthSmallest(vector<int> &nums, int k) {
        if (k > nums.size()) return -1;
        priority_queue<int> heap;
        for (int i = 0; i < nums.size(); i++) {
            if (heap.size() < k) {
                heap.push(nums[i]);
            } else if (nums[i] < heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};

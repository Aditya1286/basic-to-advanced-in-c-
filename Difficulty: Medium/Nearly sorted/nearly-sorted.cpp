class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            minHeap.push(arr[i]);

            if (minHeap.size() > k) {
                arr[index++] = minHeap.top();
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
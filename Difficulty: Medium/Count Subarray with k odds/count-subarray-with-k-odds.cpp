class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k - 1);
    }

  private:
    int atMost(vector<int>& arr, int k) {
        if (k < 0) return 0;
        int left = 0, sum = 0, count = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right] % 2;   
            
            while (sum > k) {
                sum -= arr[left] % 2;
                left++;
            }
            
            count += (right - left + 1);
        }
        return count;
    }
};

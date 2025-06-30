class Solution {
  public:
    int counto(vector<int> &arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();  // Initialize with size (no 1s found case)
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == 1) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;  
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int countmax = 0;
        int index = -1;
        
        for (int i = 0; i < arr.size(); i++) {
            int firstOneIndex = counto(arr[i]);
            int countOne = arr[i].size() - firstOneIndex;
            
            if (countOne > countmax) {
                countmax = countOne;
                index = i;
            }
        }
        return index;  
    }
};

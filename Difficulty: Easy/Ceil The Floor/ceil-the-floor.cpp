class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(), arr.end()); 

        int floorIdx = -1;
        int low = 0, high = arr.size() - 1;

       while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                floorIdx = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int ceilIdx = -1;
        low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ceilIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        int floor = (floorIdx != -1) ? arr[floorIdx] : -1;
        int ceil = (ceilIdx != -1) ? arr[ceilIdx] : -1;

        return {floor, ceil};
    }
};

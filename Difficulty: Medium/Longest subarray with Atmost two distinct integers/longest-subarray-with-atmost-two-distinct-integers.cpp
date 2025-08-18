class Solution {
  public:
    int totalElements(vector<int> &arr) {
         int l = 0, r = 0, n = arr.size(), maxLen = 0;
    unordered_map<int,int> mpp;

    while (r < n) {
        mpp[arr[r]]++;

        if (mpp.size() > 2) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]);
            }
            l++;
        }

        if (mpp.size() <= 2) {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }

    return maxLen;
    }
};
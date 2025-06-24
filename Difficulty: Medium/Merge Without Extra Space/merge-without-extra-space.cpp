class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int gap = (n + m + 1) / 2;

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < n + m) {
                int& val_i = (i < n) ? a[i] : b[i - n];
                int& val_j = (j < n) ? a[j] : b[j - n];

                if (val_i > val_j) {
                    swap(val_i, val_j);
                }

                i++;
                j++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};
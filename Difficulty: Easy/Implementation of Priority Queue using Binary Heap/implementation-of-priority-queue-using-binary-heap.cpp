class Solution {
  public:
    int extractMax() {
        if (s < 0) return -1;
        int maxVal = H[0];
        H[0] = H[s];
        s--;
        shiftDown(0);
        return maxVal;
    }
};

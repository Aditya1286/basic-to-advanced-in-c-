class Solution {
  public:
    int countSetBits(int n) {
        int count = 0;
        n++;
        for (int x = 2; x/2 <= n; x <<= 1) {
            int fullCycles = n / x;
            count += fullCycles * (x / 2);
            int remainder = n % x;
            if (remainder > x / 2) {
                count += remainder - (x / 2);
            }
        }
        return count;
    }
};

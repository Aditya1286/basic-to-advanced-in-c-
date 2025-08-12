class Solution {
  public:
    void bitManipulation(int num, int i) {
        int mask = 1 << (i - 1);

        int getBit = (num & mask) ? 1 : 0;
        int setBit = num | mask;
        int clearBit = num & (~mask);

        cout << getBit << " " << setBit << " " << clearBit;
    }
};

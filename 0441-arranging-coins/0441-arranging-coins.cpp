class Solution {
public:
    int arrangeCoins(int n) {
        long long count = 0;
        while (true) {
            long long prod = (count * (count + 1)) / 2;
            if (prod > n) break;
            count++;
        }
        return count - 1;
    }
};

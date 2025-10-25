class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = 0;
        total += 7 * weeks * (weeks + 1) / 2 + 21 * weeks;
        int start = weeks + 1;
        total += days * (2 * start + (days - 1)) / 2;
        return total;
    }
};

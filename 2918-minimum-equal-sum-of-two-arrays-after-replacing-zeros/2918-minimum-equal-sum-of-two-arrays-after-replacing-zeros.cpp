class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;
        for (int x : nums1) if (x == 0) zero1++; else sum1 += x;
        for (int x : nums2) if (x == 0) zero2++; else sum2 += x;
        long long target = max(sum1 + zero1, sum2 + zero2);
        if (zero1 == 0 && target != sum1) return -1;
        if (zero2 == 0 && target != sum2) return -1;
        return target;
    }
};

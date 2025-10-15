class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 1);
        for (int i = n - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1]) L[i] = L[i + 1] + 1;
        int lo = 1, hi = n / 2, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool ok = false;
            for (int a = 0; a + 2 * mid <= n; ++a) {
                if (L[a] >= mid && L[a + mid] >= mid) { ok = true; break; }
            }
            if (ok) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};

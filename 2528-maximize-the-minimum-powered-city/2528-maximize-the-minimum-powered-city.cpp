class Solution {
public:
    bool canAchieve(long long x, const vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<long long> base(n);
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r), R = min(n - 1, i + r);
            base[i] = pref[R + 1] - pref[L];
        }

        vector<long long> diff(n + 1, 0);
        long long added = 0, remain = k;
        for (int i = 0; i < n; ++i) {
            added += diff[i];
            long long cur = base[i] + added;
            if (cur < x) {
                long long need = x - cur;
                remain -= need;
                if (remain < 0) return false;
                added += need;
                int end = min(n - 1, i + 2 * r);
                if (end + 1 <= n) diff[end + 1] -= need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        long long sum = 0;
        for (int v : stations) sum += v;
        long long high = sum + (long long)k * (2LL * r + 1LL);
        long long low = 0, ans = 0;
        while (low <= high) {
            long long mid = (low + high) >> 1;
            if (canAchieve(mid, stations, r, k)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};

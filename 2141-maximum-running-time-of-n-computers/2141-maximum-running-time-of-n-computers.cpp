#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long lo = 0, hi = total / n;
        while (lo < hi) {
            long long mid = (lo + hi + 1) / 2;
            __int128 available = 0;
            for (long long b : batteries) available += min(b, mid);
            if (available >= (__int128)mid * n) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};

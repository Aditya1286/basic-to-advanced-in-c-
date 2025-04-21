class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long cur = 0;
        long long minPref = 0;
        long long maxPref = 0;

        for (int d : differences) {
            cur += d;
            minPref = min(minPref, cur);
            maxPref = max(maxPref, cur);
        }

        long long totalRange = upper - lower;
        long long requiredSpan = maxPref - minPref;

       if (totalRange < requiredSpan) return 0;

       return static_cast<int>(totalRange - requiredSpan + 1);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int best = 0;

        for (int i = 0; i < m; ++i) {
            // update heights for this row
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) height[j] += 1;
                else height[j] = 0;
            }

            // sort a copy of heights in non-increasing order
            vector<int> sorted = height;
            sort(sorted.begin(), sorted.end(), greater<int>());

            // consider using first k columns (k = 1..n)
            for (int k = 1; k <= n; ++k) {
                int area = sorted[k-1] * k;
                if (area > best) best = area;
            }
        }

        return best;
    }
};
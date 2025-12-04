class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;
        // skip leading 'L' (they go left off the road)
        while (i < n && directions[i] == 'L') ++i;
        // skip trailing 'R' (they go right off the road)
        while (j >= 0 && directions[j] == 'R') --j;
        int ans = 0;
        for (int k = i; k <= j; ++k) {
            if (directions[k] == 'L' || directions[k] == 'R') ++ans;
        }
        return ans;
    }
};

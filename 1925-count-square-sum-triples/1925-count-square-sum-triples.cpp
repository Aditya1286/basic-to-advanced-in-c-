#include <cmath>

class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                int s = a * a + b * b;
                int c = (int)std::sqrt(s);
                if (c * c == s && c <= n) cnt += 2;
            }
        }
        return cnt;
    }
};

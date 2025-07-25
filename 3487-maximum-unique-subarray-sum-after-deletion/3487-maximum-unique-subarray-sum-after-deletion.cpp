#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int sumPos = 0;
        int bestSingle = INT_MIN;

        for (int x : nums) {
            bestSingle = max(bestSingle, x);
            if (x > 0 && !seen.count(x)) {
                sumPos += x;
                seen.insert(x);
            }
        }

         return (sumPos > 0 ? sumPos : bestSingle);
    }
};

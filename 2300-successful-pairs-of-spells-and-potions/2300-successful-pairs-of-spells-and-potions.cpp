#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;
        
        for (int spell : spells) {
            long long p_min = (success + spell - 1) / spell; // ceil(success / spell)
            auto it = lower_bound(potions.begin(), potions.end(), p_min);
            result.push_back(potions.end() - it);
        }
        
        return result;
    }
};

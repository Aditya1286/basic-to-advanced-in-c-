#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> countMap;
        int result = 0;
        
        for (auto& d : dominoes) {
            // Normalize the domino
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b; // Since values are between 1 and 9

            result += countMap[key]; // Add how many times this domino has been seen
            countMap[key]++;
        }

        return result;
    }
};

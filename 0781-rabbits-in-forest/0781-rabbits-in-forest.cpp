class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;

        for (int answer : answers) {
            count[answer]++;
        }

        for (auto& [k, v] : count) {
            int groupSize = k + 1;
           int groups = (v + groupSize - 1) / groupSize;
            result += groups * groupSize;
        }

        return result;
    }
};

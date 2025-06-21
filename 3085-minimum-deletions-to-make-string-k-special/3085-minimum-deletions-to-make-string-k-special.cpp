class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }

        vector<int> count;
        for (auto &pair : freq) {
            count.push_back(pair.second);
        }

        sort(count.begin(), count.end());

        int n = count.size();
        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            int target = count[i];
            int deletions = 0;
            for (int j = 0; j < n; j++) {
                if (count[j] > target + k) {
                    deletions += count[j] - (target + k);
                } else if (count[j] < target) {
                    deletions += count[j];
                }
            }
            result = min(result, deletions);
        }

        return result;
    }
};

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);

       for (char c : s) {
            freq[c - 'a']++;
        }

        while (t--) {
            vector<long long> newFreq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (i == 25) {
                    newFreq[0] = (newFreq[0] + freq[i]) % MOD;
                    newFreq[1] = (newFreq[1] + freq[i]) % MOD;
                } else {
                     newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
                }
            }
            freq = newFreq;
        }

        long long result = 0;
        for (int i = 0; i < 26; ++i) {
            result = (result + freq[i]) % MOD;
        }

        return static_cast<int>(result);
    }
};

class Solution {
  public:
    int atMostK(const string &s, int k) {
        vector<int> freq(26, 0);
        int left = 0, count = 0, distinct = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int countSubstr(const string &s, int k) {
        if (k == 0) return 0;
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

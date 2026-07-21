#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int n = t.size();
        int original_ones = count(s.begin(), s.end(), '1');
        int max_gain = 0;
        for (int i = 0; i < n; ) {
            if (t[i] == '1') {
                int start = i;
                while (i < n && t[i] == '1') {
                    i++;
                }
                if (start > 0 && i < n && t[start - 1] == '0' && t[i] == '0') {
                    int left_count = 0;
                    int j = start - 1;
                    while (j >= 0 && t[j] == '0') {
                        left_count++;
                        j--;
                    }
                    int right_count = 0;
                    j = i;
                    while (j < n && t[j] == '0') {
                        right_count++;
                        j++;
                    }
                    int gain = left_count + right_count;
                    max_gain = max(max_gain, gain);
                }
            } else {
                i++;
            }
        }
        return original_ones + max_gain;
    }
};

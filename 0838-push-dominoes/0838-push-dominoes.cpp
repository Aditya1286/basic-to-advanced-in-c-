class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int left = -1;  // last seen 'L'
        int right = -1; // last seen 'R'

        for (int i = 0; i <= n; ++i) {
            char c = (i < n) ? dominoes[i] : 'R';
            if (c == 'R') {
                if (right > left) {
                    for (int j = right + 1; j < i; ++j) {
                        result[j] = 'R';
                    }
                }
                right = i;
            } else if (c == 'L') {
                if (right > left) {
                    int l = right + 1, r = i - 1;
                    while (l < r) {
                        result[l++] = 'R';
                        result[r--] = 'L';
                    }
                    // middle one (if any) remains '.'
                } else {
                    for (int j = left + 1; j < i; ++j) {
                        result[j] = 'L';
                    }
                }
                left = i;
                right = -1;
            }
        }

        return result;
    }
};

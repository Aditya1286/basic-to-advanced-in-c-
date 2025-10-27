class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for (auto &row : bank) {
            int cnt = count(row.begin(), row.end(), '1');
            if (cnt > 0) {
                res += prev * cnt;
                prev = cnt;
            }
        }
        return res;
    }
};

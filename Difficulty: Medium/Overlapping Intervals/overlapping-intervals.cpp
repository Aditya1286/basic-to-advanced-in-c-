class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> res;
        if (arr.empty()) return res;

        sort(arr.begin(), arr.end());
        res.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], arr[i][1]);
            } else {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};

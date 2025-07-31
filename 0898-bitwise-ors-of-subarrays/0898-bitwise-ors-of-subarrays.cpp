class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;

        for (int num : arr) {
            unordered_set<int> nextCur = {num};
            for (int val : cur) {
                nextCur.insert(val | num);
            }
            cur = nextCur;
            for (int val : cur) {
                res.insert(val);
            }
        }

        return res.size();
    }
};

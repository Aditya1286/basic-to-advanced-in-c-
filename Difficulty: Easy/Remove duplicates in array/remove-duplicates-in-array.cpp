class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
       unordered_set<int> seen;
    vector<int> result;

    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
    }
};

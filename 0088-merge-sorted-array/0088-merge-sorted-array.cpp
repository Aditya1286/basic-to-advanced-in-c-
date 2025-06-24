#include <algorithm>
class Solution {
public:
    void merge(vector<int>& vec1, int m, vector<int>& vec2, int n) {
    vector<int> vec;
    vec.insert(vec.end(), vec1.begin(), vec1.begin() + m);
    vec.insert(vec.end(), vec2.begin(), vec2.begin() + n);
    sort(vec.begin(), vec.end());
    vec1=vec;
    }
};
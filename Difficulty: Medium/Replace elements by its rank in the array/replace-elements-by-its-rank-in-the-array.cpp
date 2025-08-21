// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int,int> mp;
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank++;
            }
        }

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[i] = mp[arr[i]];
        }
        return result;
    }
};

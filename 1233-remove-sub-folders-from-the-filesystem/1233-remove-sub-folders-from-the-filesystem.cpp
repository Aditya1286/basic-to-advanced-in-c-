class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        string prev = "";
        for (const string& path : folder) {
            if (prev.empty() || path.find(prev + "/") != 0) {
                res.push_back(path);
                prev = path;
            }
        }
        return res;
    }
};

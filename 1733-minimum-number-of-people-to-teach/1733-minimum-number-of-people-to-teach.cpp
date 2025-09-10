#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> userLanguages(m + 1);

        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLanguages[i + 1].insert(lang);
            }
        }

        unordered_set<int> problematicUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : userLanguages[u]) {
                if (userLanguages[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
            }
        }

        int minTeach = m;
        for (int lang = 1; lang <= n; lang++) {
            int teachCount = 0;
            for (int user : problematicUsers) {
                if (userLanguages[user].count(lang) == 0) {
                    teachCount++;
                }
            }
            minTeach = min(minTeach, teachCount);
        }

        return minTeach;
    }
};

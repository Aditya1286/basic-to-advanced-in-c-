#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;

        for (string word : wordlist) {
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
            if (caseInsensitive.find(lowerWord) == caseInsensitive.end()) {
                caseInsensitive[lowerWord] = word;
            }

            string devoweledWord = lowerWord;
            for (char& c : devoweledWord) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }
            if (vowelError.find(devoweledWord) == vowelError.end()) {
                vowelError[devoweledWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            if (exactWords.count(query)) {
                result.push_back(query);
                continue;
            }

            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

            if (caseInsensitive.find(lowerQuery) != caseInsensitive.end()) {
                result.push_back(caseInsensitive[lowerQuery]);
                continue;
            }

            string devoweledQuery = lowerQuery;
            for (char& c : devoweledQuery) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }

            if (vowelError.find(devoweledQuery) != vowelError.end()) {
                result.push_back(vowelError[devoweledQuery]);
            } else {
                result.push_back("");
            }
        }

        return result;
    }
};

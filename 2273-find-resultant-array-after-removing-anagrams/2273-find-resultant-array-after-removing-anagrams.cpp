#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prevSorted = "";
        
        for (string &word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            if (sortedWord != prevSorted) {
                res.push_back(word);
                prevSorted = sortedWord;
            }
        }
        
        return res;
    }
};

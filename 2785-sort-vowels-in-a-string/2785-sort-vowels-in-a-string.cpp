#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    string sortVowels(string s) {
        std::vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }
        std::sort(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

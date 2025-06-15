class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxNum = s;
        string minNum = s;

        char maxReplace = ' ';
        for (char c : s) {
            if (c != '9') {
                maxReplace = c;
                break;
            }
        }

        if (maxReplace != ' ') {
            for (char &c : maxNum) {
                if (c == maxReplace) c = '9';
            }
        }

        char minReplace = ' ';
        if (s[0] != '1') {
            minReplace = s[0];
            for (char &c : minNum) {
                if (c == minReplace) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    minReplace = s[i];
                    break;
                }
            }
            if (minReplace != ' ') {
                for (int i = 1; i < minNum.size(); ++i) {
                    if (minNum[i] == minReplace) minNum[i] = '0';
                }
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};

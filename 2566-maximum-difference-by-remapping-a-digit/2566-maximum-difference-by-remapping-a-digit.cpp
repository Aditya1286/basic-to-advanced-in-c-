class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxNum = s, minNum = s;
        
        char toReplaceMax = ' ';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax != ' ') {
            for (char &c : maxNum) {
                if (c == toReplaceMax) c = '9';
            }
        }
        
        char toReplaceMin = s[0];
        for (char &c : minNum) {
            if (c == toReplaceMin) c = '0';
        }

        return stoi(maxNum) - stoi(minNum);
    }
};

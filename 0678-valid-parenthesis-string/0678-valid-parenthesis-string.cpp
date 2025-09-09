class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            } else if (s[i] == ')') {
                minOpen--;
                maxOpen--;
            } else {  
                minOpen--;
                maxOpen++;
            }
            
            if (minOpen < 0) minOpen = 0;
            if (maxOpen < 0) return false;
        }
        return minOpen == 0;
    }
};

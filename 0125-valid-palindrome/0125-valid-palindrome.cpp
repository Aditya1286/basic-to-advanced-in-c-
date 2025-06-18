class Solution {
public:
    bool isPalindrome(string s) {
        string normalized;
        for (char c : s) {
            if (isalnum(c)) {
                normalized += tolower(c);
            }
        }
        int left=0;
        int right=normalized.size()-1;
        return asd(normalized,left,right);
    }
    bool asd(string str,int left,int right){
        if(left>right)return true;
        if(str[left]!=str[right])return false;
        return asd(str,left+1,right-1);
    }
};
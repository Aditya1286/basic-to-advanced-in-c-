class Solution {
private:
    bool isPalind(string str){
        int n=str.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            if(str[left]==str[right]){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string str;
        for(auto it:s){
            if(isalnum(it)){
                str+=tolower(it);
            }
        }
        return isPalind(str);
    }
};
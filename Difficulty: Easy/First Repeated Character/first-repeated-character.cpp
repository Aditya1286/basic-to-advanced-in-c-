class Solution {
  public:
    string firstRepChar(string s) {
        vector<int> freq(26,0);
        string ans="-1";
        for(char c:s){
            freq[c-'a']++;
            if(freq[c-'a']==2){
                ans=c;
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxOperations(string s) {
        int br=0;
        int n=s.size();
        int i=n-1;
        int ans=0;
        while(i>=0){
            if(s[i]=='1'){
                ans+=br;
                i--;
            }
            else{
                while(i>=0 && s[i]=='0') i--;
                br++;
            }
        }
        return ans;
    }
};
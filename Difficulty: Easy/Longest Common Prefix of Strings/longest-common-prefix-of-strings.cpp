// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        string ans="";
        for(int i=0;i<arr[0].length();i++){
            char ch=arr[0][i];
            bool match = true;
            for(int j=1;j<arr.size();j++){
                if(ch!=arr[j][i] || arr[j].size()<i){
                    match=false;
                    break;
                }
            }
            if(match==false)break;
            else ans.push_back(ch);
        }
        return ans;
    }
};
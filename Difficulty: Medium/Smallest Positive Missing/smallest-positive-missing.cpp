class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        int res=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]==res){
                res++;
            }
            if(arr[i]>res){
                break;
            }
        }
        return res;
    }
};
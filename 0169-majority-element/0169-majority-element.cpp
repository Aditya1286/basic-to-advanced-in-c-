#include <unordered_map>
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int val=-1;
        int count=0;
        int mp=n/2;
        for(auto& num:mpp){
            if(num.second>mp){
                if(num.second>count){
                    val=num.first;
                    count=num.second;
                }
                else if(num.second==count){
                    val=max(num.first,val);
                    count=num.second;
                }
            }
        }
        return val;
    }
};
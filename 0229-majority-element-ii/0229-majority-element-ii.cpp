#include <algorithm>
#include <set>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> as;
      set<int> mySet(nums.begin(), nums.end());
      int n=nums.size()/3;
      for(int i:mySet){
        int d=count(nums.begin(), nums.end(), i);
        if(d>n) as.push_back(i);
        } 
      return as;
    }
};
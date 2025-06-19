
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        std::unordered_set<int> seen;
        for(int num : arr){
            if(seen.count(target - num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
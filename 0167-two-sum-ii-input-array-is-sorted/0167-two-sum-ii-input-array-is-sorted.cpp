class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int low=0;
        int high=n-1;
        vector<int> ans;
        while(low<=high){
            int sum=numbers[low]+numbers[high];
            if(sum==target){
                ans.push_back(low+1);
                ans.push_back(high+1);
                break;

            }
            else if(sum>target){
                high--;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};
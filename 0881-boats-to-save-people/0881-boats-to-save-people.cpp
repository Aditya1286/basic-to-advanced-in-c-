class Solution {
public:
    int numRescueBoats(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums.size()-1;
        int count=0;
        while(low<=high){
            int sum=nums[low]+nums[high];
            if(sum<=target){
                low++;
                high--;
                count++;
            }
            else{
                high--;
                count++;
            }
        }
        return count;
    }
};
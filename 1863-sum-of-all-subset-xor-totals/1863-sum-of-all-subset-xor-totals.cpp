class Solution {
private:
    int solve(vector<int> nums,int index,int total){
        if(index==nums.size()){
            return total;
        }
        return solve(nums,index+1,total^nums[index])+solve(nums,index+1,total);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};
class Solution {
private:
    bool dfs(int length,vector<int>& sides, int k, vector<int> nums,int index){
        if(index==nums.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(sides[i]+nums[index]<=length){
                sides[i]+=nums[index];
                if(dfs(length,sides,k,nums,index+1))return true;
                sides[i]-=nums[index];
            }
            if(sides[i]==0)break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        int length=sum/k;
        sort(nums.rbegin(),nums.rend());
        vector<int> sides(k,0);
        return dfs(length,sides,k,nums,0);
    }
};